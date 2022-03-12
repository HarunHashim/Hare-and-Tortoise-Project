#include "defs.h"


int main(int argc, char *argv[])
{
  
  int runs;
  if(argc < 2){
    runs=100;
  }else{
    runs=atoi(argv[1]);     
  }

  
  srand( (unsigned)time( NULL ) );

  
  
  StatsType *scenario_statistics[NUM_SCENARIOS];
  for(int i =0 ; i<NUM_SCENARIOS ; i++){
    init_stats(&scenario_statistics[i]);
  }

 
  for(int i=0 ; i<runs ;i++){
    
    DequeType pirate_crews[NUM_SCENARIOS];
    FighterType *tort_heroes[NUM_SCENARIOS];
    FighterType *hare_heroes[NUM_SCENARIOS];
    RunSpecsType *scenario_RunSpecs[NUM_SCENARIOS];

    //Deque initialization
    initDeque(&pirate_crews[0]);
    init_crew(&pirate_crews[0]);
    
    for(int j=1 ; j<NUM_SCENARIOS ;j++ ){
      initDeque(&pirate_crews[j]);
      deepCopy(&pirate_crews[0] , &pirate_crews[j]);
    }
    
    //Initializing heroes 
    init_heroes(tort_heroes , hare_heroes);

    //Specs initialization
    for(int w=0 ; w<NUM_SCENARIOS ;w++ ){
      init_RunSpecsType( &pirate_crews[w] , tort_heroes[w] , hare_heroes[w] , scenario_statistics[w] , &scenario_RunSpecs[w] );
    }
        

    pthread_t scenario_threads[NUM_SCENARIOS];   
    for(int q=0 ; q<NUM_SCENARIOS ; q++){
      pthread_create(&scenario_threads[q], NULL, scenario_run, scenario_RunSpecs[q]);
      
    }

    for( int f =0; f<NUM_SCENARIOS ; f++){
      pthread_join(scenario_threads[f], NULL);
      
    }
      
    //Cleaning The run
    
    cleanPirateCrews(pirate_crews); 
    cleanHeroes(tort_heroes , hare_heroes);
    cleanSpecs(scenario_RunSpecs);
  }
  
  //Presenting and cleaning stats
  
  printStats(scenario_statistics , runs);
  cleanStats(scenario_statistics);

 
  return 0;
}

/*
  Function:  randm
  Purpose:   returns a pseudo randomly generated number, 
             in the range 0 to (max - 1), inclusively
       in:   upper end of the range of the generated number
   return:   randomly generated integer in the range [0, max-1) 
*/
int randm(int max)
{
  double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 

  return (int)(r * max);
}

