#include "defs.h"

/*
  Function:  init_RunSpecsType
  Purpose:   This function allocates memory for a new RunspecsType and initiallizes all its fields using the given parameters.
       in:   pointer to the deque of pirates 
             pointer to the tortiose hero
             pointer to the hare hero
             pointer to the stats of the curr scenario
      out:   the initialized RunspecsType is returned using the output parameter (**specs)
   
*/
void init_RunSpecsType(DequeType *d , FighterType *tort , FighterType *hare , StatsType *stats ,RunSpecsType **specs){
    *specs= malloc(sizeof(RunSpecsType));
    (*specs)->pirates= d;
    (*specs)->tort= tort;
    (*specs)->hare= hare;
    (*specs)->stats= stats;

    

}

/*
  Function:  init_FightSpecsType
  Purpose:   This function allocates memory for a new FightSpecsType and initiallizes all its fields using the given parameters.
       in:   pointer to the deque of pirates 
             pointer to the hero taking part in the fight
             Direction type showing which end the hero is fighting
             pointer to mutex which ensures the deque is accessd by one of the fight threads at a time

      out:   the initialized FightSpecsType is returned using the output parameter (**FST)
   
*/
void init_FightSpecsType(FighterType *hero , DequeType *pirates , DirectionType direction , sem_t *mutex , FightSpecsType **FST){
    *FST=malloc(sizeof(FightSpecsType));
    (*FST)->hero=hero;
    (*FST)->pirates=pirates;
    (*FST)->dir=direction;   
    (*FST)->dqMutex=mutex;

}

/*
  Function:  cleanSpecs
  Purpose:   free's the RunSpecsType data for each scenario
       in:   pointer to RunSpecsType array to be cleaned
   
*/
void cleanSpecs(RunSpecsType *specs[]){
    for(int i=0;i<NUM_SCENARIOS;  i++){
        free(specs[i]);
    }
}