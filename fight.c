#include "defs.h"

/*
  Function:  fight
  Purpose:   this function simulates a fight between a pirate and a hero .The fight goes on until one of the two's
             health hits zero
       in:   pointer to the hero
             pointer to the pirate
   
*/
void fight(FighterType *hero , FighterType *pirate){
    
    while(hero->health>0 && pirate->health>0){
        int hero_damage;
        int pir_damage;
        
        
        //calculating the hero damage
        if(hero->strength - pirate->armour <=0){
            hero_damage=0;
        }else{
            hero_damage=hero->strength - pirate->armour;
        }

        //Hero hits pirate
        pirate->health= pirate->health - hero_damage;
        
        if(pirate->health<=0){
            hero->health +=3;
            if(hero->health>HERO_HEALTH){
                hero->health=HERO_HEALTH;
            }
           
            pirate->health=0;
            
            break;
        }
        
        //Pirates strength is randomly increased first 
        int temporary_boost = randm(pirate->strength-1);
        pirate->strength += temporary_boost;


        //calculating pirates damage
        if( (pirate->strength - hero->armour) <=0){
            pir_damage=0;
        }else{
            pir_damage=pirate->strength - hero->armour;
        }

        

        //Pirate hits hero
        hero->health = hero->health - pir_damage;
        
        //Removing temporary strength boost
        pirate->strength -= temporary_boost;

        if(hero->health<=0){
            hero->health=0;
            break;
        }

        
    }
    
    
    
}
