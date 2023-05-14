// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr){}
void Train::addCage(bool light){
  Cage*  icage = new Cage;
  ncage->light = light;
  if(first == nullptr){
    first = icage;
    first->next = first;
    first->prev = first;
  }
  icage->next = first;
  icage->prev = first->prev;
  first->prev->next = icage;
  first->prev = icage;
}

int Train::getLength(){
  Cage* current = first;
  current->light = true;
  int count = 0;
  while(current){
    current = current->next;
    if(current->light == false){
      count++;
      countOp++;
    }else{
      current->light = false;
      countOp++;
      count++;
      for(int i = 0; i < count; i++){
        current = current->prev;
        countOp++;
      }
      if(current->light == false) 
        return count;
      else
        count = 0;
    }
  }
  return 0;
}

int Train::getOpCount() {
  return countOp;
}
