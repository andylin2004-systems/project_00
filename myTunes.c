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
    int slot;
    if (song->artist[0] >= 'A' && song->artist[0] <= 'Z')
    {
        slot = song->artist[0] - 'A';
    }
    else if (song->artist[0] >= 'a' && song->artist[0] <= 'z')
    {
        slot = song->artist[0] - 'a';
    }else{
        slot = 26;
    }
    if (library[slot] == NULL){
        addToFront(library[slot], song);
    }
}