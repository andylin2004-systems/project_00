#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct songNode
{
    char name[100];
    char artist[100];
    struct songNode *next;
};

int checkIfShouldPlaceAlphabet(struct songNode *prev, struct songNode *toInsert, struct songNode *next);

struct songNode *createNode(char name[100], char artist[100])
{
    struct songNode *new = malloc(sizeof(struct songNode));
    strcpy(new->name, name);
    strcpy(new->artist, artist);
    return new;
}

struct songNode *addToFront(struct songNode *front, struct songNode *toAdd)
{
    toAdd->next = front;
    front = toAdd;
    return toAdd;
}

struct songNode * addBasedOnAlphabet(struct songNode *front, struct songNode *toInsert)
{
    struct songNode *prev = front;
    struct songNode *next = front->next;
    if (strcmp(front->artist, toInsert->artist) > 0 || (strcmp(front->artist, toInsert->artist) == 0 && strcmp(front->name, toInsert->name) > 0) && prev != NULL && next == NULL)
    {
        return addToFront(front, toInsert);
    }
    while (next)
    {
        if (checkIfShouldPlaceAlphabet(prev, toInsert, next))
        {
            prev->next = toInsert;
            toInsert->next = next;
            return front;
        }
        else
        {
            prev = next;
            next = next->next;
        }
    }
    //assuming that there is nothing else after
    prev->next = toInsert;
    return front;
}

int checkIfShouldPlaceAlphabet(struct songNode *prev, struct songNode *toInsert, struct songNode *next)
{
    if (strcmp(prev->artist, toInsert->artist) < 0 && strcmp(toInsert->artist, next->artist) < 0)
    {
        if (strcmp(prev->name, toInsert->name) < 0 && strcmp(toInsert->name, next->name) < 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

void print_node(struct songNode *node)
{
    printf("{%s, %s}", node->artist, node->name);
}

void print_list(struct songNode *front)
{
    struct songNode *current = front;
    while (current)
    {
        print_node(current);
        printf(", ");
        current = current->next;
    }
}

struct songNode *findNodeByNameAndArtist(struct songNode *front, char name[100], char artist[100])
{
    struct songNode *current = front;
    while (current)
    {
        if (strcmp(current->artist, artist) == 0 && strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct songNode *findNodeByArtist(struct songNode *front, char artist[100])
{
    struct songNode *current = front;
    while (current)
    {
        if (strcmp(current->artist, artist) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct songNode *returnRandomNode(struct songNode *front)
{
    srand(time(NULL));
    struct songNode *current = front;
    struct songNode *chosenOne = current;
    int i;
    for (i = 2; current; i++)
    {
        if (rand() % i == 0)
        {
            chosenOne = current;
        }
        current = current->next;
    }
    return chosenOne;
}

void removeNodeByNameAndArtist(struct songNode *front, char name[100], char artist[100])
{
    struct songNode *prev = front;
    struct songNode *current = front;
    struct songNode *next = current->next;
    while (current)
    {
        print_node(current);
        if (strcmp(current->artist, artist) == 0 && strcmp(current->name, name) == 0)
        {
            if (prev == current)
            {
                front = current->next;
                return;
            }
            else
            {
                prev->next = next;
                return;
            }
        }
        prev = current;
        current = next;
        next = next->next;
    }
}

void freeList(struct songNode *front)
{
    struct songNode *current = front;
    while (current)
    {
        struct songNode *temp = current;
        free(current);
        current = current->next;
    }
}