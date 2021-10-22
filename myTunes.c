#include <stdio.h>
#include "songNode.h"

struct songNode* library[27];

void allocateSongs(){
    int i;
    for (i = 0; i < 27; i++){
        library[i] = malloc(sizeof(struct songNode));
    }
}

int whereInArray(struct songNode* song){
    if (song->artist[0] >= 'A' && song->artist[0] <= 'Z')
    {
        return song->artist[0] - 'A';
    }
    else if (song->artist[0] >= 'a' && song->artist[0] <= 'z')
    {
        return song->artist[0] - 'a';
    }else{
        return 26;
    }
}

void addSong(struct songNode* song){
    int slot = whereInArray(song);
    if (library[slot] == NULL)
    {
        addToFront(library[slot], song);
    }
    else
    {
        addBasedOnAlphabet(library[slot], song);
    }
}

