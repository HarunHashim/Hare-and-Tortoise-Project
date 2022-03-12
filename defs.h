#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_RUNS       100
#define NUM_PIRATES     10
#define NUM_SCENARIOS    3   //where can i use this constant????

#define TORT_STRENGTH    5
#define TORT_ARMOUR      8
#define HARE_STRENGTH    8
#define HARE_ARMOUR      5
#define HERO_HEALTH     20
#define PIRATE_HEALTH   10
#define SWORD_STRENGTH   2

#define MAX_STR         64

typedef enum { SUCCESS, FAILURE, PART_SUCCESS, RES_UNKNOWN } ResultType;
typedef enum { FRONT, BACK } DirectionType;

typedef struct {	// Stats for one scenario, accumulated over all runs
  int numSuccess;
  int numPartSuccess;
  int numFailure;
} StatsType;

typedef struct {	// One fighter:  Tortoise, Hare, or Pirate
  int  strength;
  int  armour;
  int  health;
} FighterType;

typedef struct Node {
  FighterType  *data;
  struct Node  *next;
} NodeType;

typedef struct {	// Stores the fighting pirates for one scenario
  NodeType *head;
  NodeType *tail;
} DequeType;

typedef struct {	// Specs for one scenario of one run
  DequeType   *pirates;
  FighterType *tort;
  FighterType *hare;
  StatsType   *stats;
} RunSpecsType;

typedef struct {	// Specs for one fight of one scenario of one run
  FighterType  *hero;
  DequeType    *pirates;
  DirectionType dir;
  sem_t        *dqMutex;
} FightSpecsType;


int randm(int);		// Pseudo-random number generator function


#endif



//Deque functions
void initDeque(DequeType *d );
void add_Back_Deque(DequeType *d, FighterType *f);
void remove_Back_Deque(DequeType *d, FighterType **f);
void remove_Front_Deque(DequeType *d, FighterType **f);
void deepCopy(DequeType *d , DequeType *d2);
void deep_copy_pirate(FighterType* new, FighterType* orig);
void cleanDeque(DequeType *d);


//fighter functions
void init_fighter(int strength , int armour , int health , FighterType **fighter);
void init_crew(DequeType *d);
void init_heroes(FighterType *t_heroes[], FighterType *h_heroes[] );
void cleanHeroes(FighterType *t_heroes[] ,FighterType *h_heroes[] );
void cleanPirateCrews(DequeType pirate_crews[]);

//specs functions
void init_RunSpecsType(DequeType *d , FighterType *t , FighterType *h , StatsType *stats ,RunSpecsType **specs);
void init_FightSpecsType(FighterType *hero , DequeType *pirates , DirectionType direction , sem_t *mutex , FightSpecsType **FST);
void cleanSpecs(RunSpecsType *specs[]);

//threads functions
void *scenario_run(void*);
void *fight_thread(void*);


//fight functions
void fight(FighterType *hero , FighterType *pirate);


//stats functions
void update_scen_stats( StatsType *s , ResultType r);
void scen_outcome(RunSpecsType *curr_specs);
void format_Scenario(StatsType *s ,int runs  , int scen_number, char *scenStr);
int percentage_conv(int number , int runs);
void init_stats(StatsType **stats);
void printStats(StatsType *scenario_stats[], int runs);
void cleanStats(StatsType *scenario_stats[]);
