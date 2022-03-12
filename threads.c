#include "defs.h"

/*
  Function:  scenario_run
  Purpose:   This function is called by a thread inorder to simulate the fights which
             will be happening in one scenario . This happens concurrently between  two heroes 
             and one crew of pirates .
       in:   Runspecs type pointer in form of an argument
   
*/
void *scenario_run(void *arg) {

    RunSpecsType *run_specs;
    run_specs= ((RunSpecsType *)arg);

    sem_t deque_mutex;
    
    if (sem_init(&deque_mutex, 0, 1) < 0) {
        printf("semaphore initialization error\n");
        exit(1);
    }

    FightSpecsType *t_hero;  //where tortoise is the hero
    FightSpecsType *h_hero;  //where hare is the hero

    init_FightSpecsType(run_specs->tort ,run_specs->pirates ,FRONT , &deque_mutex ,&t_hero);
    init_FightSpecsType(run_specs->hare ,run_specs->pirates ,BACK , &deque_mutex ,&h_hero);

    pthread_t f1, f2;
    pthread_create(&f1, NULL, fight_thread, t_hero ); 
    pthread_create(&f2, NULL, fight_thread, h_hero ); 
    pthread_join(f1, NULL);
    pthread_join(f2, NULL);

    scen_outcome(run_specs);
    
    free(t_hero);
    free(h_hero);

    return(0);

    }

/*
  Function:  fight_thread
  Purpose:   This function is called by the scenario_run inorder to simulate the fight which should 
             happening at both ends of the deque , not concurrently though. The deque will be protected by a mutex
             which will enablle to be accessed at one end at a time. The fight will go on until either the heroes are 
             both dead or all pirates are dead.
       in:   FightsSpecs type pointer in form of an argument
   
*/
void *fight_thread(void *arg){
    

    FightSpecsType *fight_specs;
    fight_specs =((FightSpecsType *)arg);


    
    while(fight_specs->pirates->head!=NULL  && fight_specs->hero->health>0){

        if (sem_wait(fight_specs->dqMutex) < 0) {
            printf("semaphore wait error\n");
            exit(1);
        }
        
        FighterType  *curr_pir;
        
        if(fight_specs->dir==FRONT){
            remove_Front_Deque(fight_specs->pirates , &curr_pir);

        }else if(fight_specs->dir==BACK){
            remove_Back_Deque(fight_specs->pirates , &curr_pir);

        }
        
        if(curr_pir!=NULL){    
            fight(fight_specs->hero , curr_pir); 
            free(curr_pir); 
            usleep(10000);
        }
        
        
        if (sem_post(fight_specs->dqMutex) < 0) {
            printf("semaphore post error\n");
            exit(1);
        }
        
    }

    return (0);
}


