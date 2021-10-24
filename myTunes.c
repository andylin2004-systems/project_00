#include <stdio.h>
#include <strings.h>
#include <time.h>
#include <stdlib.h>
#include "songNode.h"

struct songNode *allocateSongs()
{
    struct songNode *library = calloc(27, sizeof(struct songNode));
    return library;
}

int whereInArray(char artist[100])
{
    if (artist[0] >= 'A' && artist[0] <= 'Z')
    {
        return artist[0] - 'A';
    }
    else if (artist[0] >= 'a' && artist[0] <= 'z')
    {
        return artist[0] - 'a';
    }
    else
    {
        return 26;
    }
}

void addSong(struct songNode *library[], struct songNode *song)
{
    int slot = whereInArray(song->artist);
    if (library[slot] == NULL)
    {
        library[slot] = addToFront(library[slot], song);
    }
    else
    {
        library[slot] = addBasedOnAlphabet(library[slot], song);
    }
}

struct songNode *findSongByNameAndArtist(struct songNode *library[], char name[100], char artist[100])
{
    int slot = whereInArray(artist);
    return findNodeByNameAndArtist(library[slot], name, artist);
}

struct songNode *findSongByArtist(struct songNode *library[], char artist[100])
{
    int slot = whereInArray(artist);
    return findNodeByArtist(library[slot], artist);
}

void printSongListByAlphabet(struct songNode *library[], char letter)
{
    int slot = whereInArray(&letter);
    if (library[slot]){
        print_list(library[slot]);
    }else{
        printf("No songs found for artists beginning with %c", letter);
    }
}

void printSongByArtist(struct songNode *library[], char artist[100])
{
    struct songNode *current = findSongByArtist(library, artist);
    if (current == NULL)
    {
        printf("no songs by %s found", artist);
    }
    while (current && strcmp(current->artist, artist) == 0)
    {
        print_node(current);
        printf(", ");
        current = current->next;
    }
}

void printLibrary(struct songNode *library[])
{
    int i;
    for (i = 0; i < 26; i++)
    {
        print_list(library[i]);
    }
}

void shuffle(struct songNode *library[], int count)
{
    srand(time(NULL));
    int i;
    int slot;
    for (i = 0; i < count; i++)
    {
        slot = rand() % 27;
        if (library[slot] == NULL){
            i--;
            continue;
        }
        print_node(returnRandomNode(library[slot]));
        printf(", ");
    }
}

void deleteSong(struct songNode *library[], char name[100], char artist[100])
{
    int slot = whereInArray(artist);
    library[slot] = removeNodeByNameAndArtist(library[slot], name, artist);
}

void clearLibrary(struct songNode *library[])
{
    int i;
    for (i = 0; i < 27; i++)
    {
        library[i] = freeList(library[i]);
    }
}