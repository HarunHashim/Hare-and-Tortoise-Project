#include "defs.h"

/*
  Function:  init_fighter
  Purpose:   initializes the fighter passed into the fuction with the attributes given as parameters 
       in:   strength value
             armour value 
             health value 
      out:   the initialized fighter is returned using the output parameter , the fighter type double pointer -> **fighter
    
*/
void init_fighter(int strength , int armour , int health , FighterType **fighter){
    *fighter = malloc(sizeof(FighterType));
    (*fighter)->strength=strength;   	
    (*fighter)->armour= armour;   
    (*fighter)->health=health;
}

/*
  Function:  init_crew
  Purpose:   this function initializes 10 pirates and adds them into the deque passed in.
       in:   pointer to the deque 
    
*/
void init_crew(DequeType *d){
    FighterType *curr_pir;
    for(int i=0 ; i<NUM_PIRATES; i++){
        init_fighter( randm(5)+5 , randm(4)+1, PIRATE_HEALTH ,&curr_pir);
        add_Back_Deque(d, curr_pir);
    }
    
}

/*
  Function:  init_heroes
  Purpose:   this function initiallizes a different hare and tortoise hero for each scenario using the specified
             attributes for each scenario
       in:   pointer to array of the tortoise heroes for each scenario 
             pointer to array of the hare heroes for each scenario 
   
*/
void init_heroes(FighterType *t_heroes[], FighterType *h_heroes[] ){
    
    //Scenario 1 heroes
    init_fighter((TORT_STRENGTH + SWORD_STRENGTH) , TORT_ARMOUR , HERO_HEALTH , &t_heroes[0]); 
    init_fighter(HARE_STRENGTH , HARE_ARMOUR , HERO_HEALTH , &h_heroes[0]);     
  
    //Scenario 2 heroes
    init_fighter(TORT_STRENGTH  , TORT_ARMOUR , HERO_HEALTH , &t_heroes[1]);  
    init_fighter(HARE_STRENGTH + SWORD_STRENGTH, HARE_ARMOUR , HERO_HEALTH , &h_heroes[1]);      
  
    //Scenario 3 heroes
    init_fighter(TORT_STRENGTH  , TORT_ARMOUR , HERO_HEALTH , &t_heroes[2]);  
    init_fighter(HARE_STRENGTH , HARE_ARMOUR , HERO_HEALTH , &h_heroes[2]);      
}

/*
  Function:  cleanHeroes
  Purpose:   this free's each and every hero for each scenario 
       in:   pointer to array of the tortoise heroes for each scenario 
             pointer to array of the hare heroes for each scenario
   
*/
void cleanHeroes(FighterType *t_heroes[], FighterType *h_heroes[] ){
    for(int i=0 ; i<NUM_SCENARIOS;i++){
        free(t_heroes[i]);
        free(h_heroes[i]);
    }
}

/*
  Function:  cleanPirateCrews
  Purpose:   free's the pirate Deque for each scenario
       in:   pointer to array of the pirate crews for each scenario 
   
*/
void cleanPirateCrews(DequeType pirate_crews[]){
    for(int i=0; i<NUM_SCENARIOS; i++){
        cleanDeque(&pirate_crews[i]);
    }
}