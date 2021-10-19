#include <stdio.h>

struct song_node{
    char name[100];
    char artist[100];
    struct song_node *next;
};

struct song_node meme[27];