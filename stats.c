#include "defs.h"

/*
  Function:  init_stats
  Purpose:   initializes the stats
       in:   a StatsType double pointer 
    
*/
void init_stats( StatsType **stats){
  *stats = malloc (sizeof(StatsType));
  (*stats)->numSuccess=0;
  (*stats)->numPartSuccess=0;
  (*stats)->numFailure=0;
}

/*
  Function:  update_scen_stats
  Purpose:   this updates the number of Success , partSuccess or failure for the statsType 
             passed into the function based on the result passed into the function. 
       in:   StatsType pointer to the stats to be updated 
             ResultType for the result of the scenario outcome 
   
*/
void update_scen_stats( StatsType *s , ResultType r){
  if(r==SUCCESS){
    s->numSuccess+=1;

  }else if(r==PART_SUCCESS){
    s->numPartSuccess+=1;

  }else if(r==FAILURE){
    s->numFailure+=1;
  }

}


/*
  Function:  scen_outcome
  Purpose:   This is used to determine the outcome of the scenario using the current Runspecs
             of the scenario 
       in:   a RunSpecsType pointer to the current specs of the scenario
    
*/
void scen_outcome(RunSpecsType *curr_specs){
  if(curr_specs->pirates->head==NULL){
       
    if(curr_specs->hare->health==0 || curr_specs->tort->health==0){
      update_scen_stats(curr_specs->stats , PART_SUCCESS);

    }else if(curr_specs->hare->health>0 && curr_specs->tort->health>0){
      update_scen_stats(curr_specs->stats , SUCCESS);
    }
  }else{
      if(curr_specs->hare->health==0 && curr_specs->tort->health==0){  
        update_scen_stats(curr_specs->stats , FAILURE);      
      }
    }

}

/*
  Function:  printStats
  Purpose:   Used to print the stats of the scenario and the total number of runs done 
       in:   pointer to the stats array with the stats for each scenario 
             total number of runs 
   output:   prints the stats of each scenario in a more presentable way 
*/
void printStats(StatsType *scenario_stats[], int runs){
  char scen_str[MAX_STR];

  printf("+---------------------------------------------------------+\n");
  printf("| Hero with sword   | %% success  | %% partial  | %% failure |\n");

  for(int i=0; i<NUM_SCENARIOS ; i++){
    printf("+---------------------------------------------------------+\n");
    format_Scenario( scenario_stats[i], runs  , i, scen_str);
    printf("%s",scen_str);
  }
  printf("+---------------------------------------------------------+\n");
  printf("Total runs: %d ", runs);
}

/*
  Function:  format_Scenario
  Purpose:   This is used to create an out string which presents the outcome of each scenario in a readable format
       in:   -Statstype pointer to the current scenario stats 
             -total number of runs 
             -scen_number 
             -string to be updated 
   
*/
void format_Scenario(StatsType *s , int runs  , int scen_number, char *scenStr){
  char sword_holder[MAX_STR];
  int succ_p = percentage_conv(s->numSuccess , runs);
  int part_s_p = percentage_conv(s->numPartSuccess , runs);
  int failure_p = percentage_conv(s->numFailure , runs);
  
  if(scen_number==0){
    strcpy(sword_holder ,"Tortoise");
  }else if(scen_number==1){
    strcpy(sword_holder, "Hare");
  }else{
    strcpy (sword_holder, "NONE");
  }

  sprintf(scenStr , "|%15s   | %10d | %10d | %10d |\n",sword_holder , succ_p ,part_s_p , failure_p);

}

/*
  Function:  percentage_conv
  Purpose:   converts the stats into percentage format using the total number of runs performed
       in:   the number representing the stats (numSuccess ,numPartSucces or numFailure) 
             total number of runs 
   return:   number representing the percentage of the total number of the particular result 
             against the total number of runs
*/
int percentage_conv(int number , int runs){
  return (number*100)/runs;
}


/*
  Function:  cleanStats
  Purpose:   free's the scenario stats data for each scenario in the array
       in:   pointer to array of StatsType to be cleaned 
   
*/
void cleanStats(StatsType *scenario_stats[]){
  for(int i=0 ; i<NUM_SCENARIOS ; i++){
    free(scenario_stats[i]);
  }
}