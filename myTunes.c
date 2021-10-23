#include <stdio.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include "songNode.h"

struct songNode * allocateSongs(){
    struct songNode *library = calloc(27, sizeof(struct songNode));
    return library;
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

void addSong(struct songNode *library[], struct songNode* song){
    int slot = whereInArray(song->artist);
    printf("e");
    if (library[slot] == NULL)
    {
        library[slot] = addToFront(library[slot], song);
    }
    else
    {
        addBasedOnAlphabet(library[slot], song);
    }
}

struct songNode* findSongByNameAndArtist(struct songNode *library[], char name[100], char artist[100]){
    int slot = whereInArray(artist);
    return findNodeByNameAndArtist(library[slot], name, artist);
}

struct songNode* findSongByArtist(struct songNode *library[], char artist[100]){
    int slot = whereInArray(artist);
    return findNodeByArtist(library[slot], artist);
}

void printSongListByAlphabet(struct songNode *library[], char letter){
    int slot = whereInArray(&letter);
    print_list(library[slot]);
}

void printSongByArtist(struct songNode *library[], char artist[100]){
    struct songNode *current = findSongByArtist(library, artist);
    while (strcmp(current->artist, artist) == 0){
        print_node(current);
        current = current->next;
    }
}

void printLibrary(struct songNode *library[]){
    int i;
    for (i = 0; i < 26; i++){
        print_list(library[i]);
    }
}

void shuffle(struct songNode *library[], int count){
    srand(time(NULL));
    int i;
    for (i = 0; i < count; i++){
        int slot = rand() % 27;
        print_node(returnRandomNode(library[slot]));
    }
}

void deleteSong(struct songNode *library[], char name[100], char artist[100]){
    int slot = whereInArray(artist);
    removeNodeByNameAndArtist(library[slot], name, artist);
}

void clearLibrary(struct songNode *library[]){
    int i;
    for (i = 0; i < 27; i++){
        freeList(library[i]);
    }
}