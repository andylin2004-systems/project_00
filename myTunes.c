#include <stdio.h>
#include "songNode.h"

struct songNode* library[27];

void allocateSongs(){
    int i;
    for (i = 0; i < 27; i++){
        library[i] = malloc(sizeof(struct songNode));
    }
}

void addSong(struct songNode* song){
    
}