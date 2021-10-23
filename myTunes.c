#include <stdio.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include "songNode.h"

struct songNode* library[27];

void allocateSongs(){
    int i;
    for (i = 0; i < 27; i++){
        library[i] = malloc(sizeof(struct songNode));
    }
}

int whereInArray(char artist[100]){
    if (artist[0] >= 'A' && artist[0] <= 'Z')
    {
        return artist[0] - 'A';
    }
    else if (artist[0] >= 'a' && artist[0] <= 'z')
    {
        return artist[0] - 'a';
    }else{
        return 26;
    }
}

void addSong(struct songNode* song){
    int slot = whereInArray(song->artist);
    if (library[slot] == NULL)
    {
        addToFront(library[slot], song);
    }
    else
    {
        addBasedOnAlphabet(library[slot], song);
    }
}

struct songNode* findSongByNameAndArtist(char name[100], char artist[100]){
    int slot = whereInArray(artist);
    return findNodeByNameAndArtist(library[slot], name, artist);
}

struct songNode* findSongByArtist(char artist[100]){
    int slot = whereInArray(artist);
    return findNodeByArtist(library[slot], artist);
}

void printSongListByAlphabet(char letter){
    int slot = whereInArray(&letter);
    print_list(library[slot]);
}

void printSongByArtist(char artist[100]){
    struct songNode *current = findSongByArtist(artist);
    while (strcmp(current->artist, artist) == 0){
        print_node(current);
        current = current->next;
    }
}

void printLibrary(){
    int i;
    for (i = 0; i < 26; i++){
        print_list(library[i]);
    }
}

void shuffle(int count){
    srand(time(NULL));
    int i;
    for (i = 0; i < count; i++){
        int slot = rand() % 27;
        print_node(returnRandomNode(library[slot]));
    }
}

void deleteSong(char name[100], char artist[100]){
    int slot = whereInArray(artist);
    removeNodeByNameAndArtist(library[slot], name, artist);
}

void clearLibrary(){
    int i;
    for (i = 0; i < 27; i++){
        freeList(library[i]);
    }
    allocateSongs();
}