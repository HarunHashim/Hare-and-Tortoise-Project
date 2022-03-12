#include "defs.h"


/*
  Function:  initDeque
  Purpose:   initiallizes the deque passed in as a parameter
       in:   pointer to the deque being initialized 
   
*/
void initDeque(DequeType *d ){
    d->head=NULL;
    d->tail=NULL;
    
}

/*
  Function:  add_Back_Deque
  Purpose:   it adds the fighter type to the back of the deque passed into the function
       in:   Pointer to the deque to be updated  
             Pointer to the fighter type to be added 
    
*/
void add_Back_Deque(DequeType *d, FighterType *f){
    NodeType *new_f;  
    new_f = malloc(sizeof(NodeType));

    new_f->data=f;
    new_f->next=NULL;

    if(d->head==NULL){
        
        d->head= new_f;
        d->tail= new_f;
    }else{
        
        if(d->head==d->tail){
            d->head->next=new_f;
            d->tail->next=new_f;
            d->tail=new_f;
            
        }else{
            d->tail->next=new_f;
            d->tail=new_f;
        }
    }


}

/*
  Function:  remove_Back_Deque
  Purpose:   removes a fighter Type from the back of the deque and 
             gives the fighter type removed as output using the Fighter type double pointer (output parameter).
       in:   Pointer to the deque 
      out:   Fighter type double pointer -> output parameter
   output:   The fighter type removed from the deque.

*/

void remove_Back_Deque(DequeType *d, FighterType **f){
    NodeType *curr_Node;
    
    if(d->tail==NULL){
        *f=NULL;
    }   
    
    else{
        curr_Node=d->tail;
        *f = d->tail->data;
        if(d->tail==d->head){
                
            d->tail=NULL;
            d->head=NULL;
    
        }else{

            NodeType *prev = NULL;
            NodeType *currNode = d->head;
            
            while (currNode!=d->tail){
                prev=currNode;
                currNode=currNode->next;
            }
            prev->next=NULL;
            d->tail=prev;

            }
        free(curr_Node);

        }
}

/*
  Function:  remove_Front_Deque
  Purpose:   removes a fighter Type from the front of the deque and 
             gives the fighter type removed as output using the Fighter type double pointer (output parameter).
       in:   Pointer to the deque 
      out:   Fighter type double pointer -> output parameter
   output:   The fighter type removed from the deque.

*/

void remove_Front_Deque(DequeType *d, FighterType **f){
    NodeType *curr_Node;
    
    if(d->head==NULL){
        *f=NULL;
    }   
    
    else{
        *f = d->head->data;
        curr_Node=d->head;
        if(d->head==d->tail){
            
            d->head=d->tail=NULL;

        }else{
            d->head=d->head->next;
        }

        free(curr_Node); 
    }
    
}


/*
  Function:  deepCopy
  Purpose:   creates a deep copy of the first deque  into the second deque .It copies all elements of
             the first deque into the second deque. 
       in:   Pointer to original deque 
             pointer to the copy deque 
   
*/
void deepCopy(DequeType *d , DequeType *d2){
    
    NodeType *curr=d->head;
    while(curr!=NULL){
        FighterType* newFighter = malloc(sizeof(FighterType));
        deep_copy_pirate(newFighter, curr->data);
        add_Back_Deque(d2 , newFighter);
        curr=curr->next;
    }

    return ;
}

/*
  Function:  deep_copy_pirate
  Purpose:   this function copies the stats of the first pirate into the new pirate passed in as the
             second parameter  
       in:    pointer to the new pirate 
              pointer to the original pirate  
  
*/
void deep_copy_pirate(FighterType* new, FighterType* orig){
    new->armour = orig->armour;
    new->health = orig->health;
    new->strength = orig->strength;
    
}


/*
  Function:  cleanDeque
  Purpose:   free's the data in the deque passed into the function
       in:   pointer to deque to be cleaned 
   
*/

void cleanDeque(DequeType *d){
    NodeType *curr= d->head;
    NodeType *prev= NULL;
    while(curr!=NULL){
        prev=curr;
        curr=curr->next;
        if(prev!=NULL){
            free(prev->data);
            free(prev);
        }
    }
    
    
}
