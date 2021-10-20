#include <stdio.h>
#include <string.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node* addToFront(struct song_node* front, struct song_node* toAdd){
    toAdd->next = front;
    return toAdd;
}

void addBasedOnAlphabet(struct song_node* front, struct song_node* toInsert){
    struct song_node *prev = front;
    struct song_node *next = front->next;
    while (next)
    {
        if (checkIfShouldPlaceAlphabet(prev, toInsert, next)){
            prev->next = toInsert;
            toInsert->next = next;
            return;
        }else{
            prev = next;
            next = next->next;
        }
    }
}

int checkIfShouldPlaceAlphabet(struct song_node* prev, struct song_node* toInsert, struct song_node* next){
    if (strcmp(prev->artist, toInsert->artist) < 0 && strcmp(toInsert->artist, next->artist) < 0){
        if (strcmp(prev->name, toInsert->name) < 0 && strcmp(toInsert->name, next->name) < 0){
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}