#include <stdio.h>
#include <string.h>

struct songNode{
    char name[100];
    char artist[100];
    struct songNode *next;
};

int checkIfShouldPlaceAlphabet(struct songNode *prev, struct songNode *toInsert, struct songNode *next);

struct songNode* addToFront(struct songNode* front, struct songNode* toAdd){
    toAdd->next = front;
    return toAdd;
}

void addBasedOnAlphabet(struct songNode* front, struct songNode* toInsert){
    struct songNode *prev = front;
    struct songNode *next = front->next;
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

int checkIfShouldPlaceAlphabet(struct songNode* prev, struct songNode* toInsert, struct songNode* next){
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

void print_node(struct songNode* node){
    printf("%s by %s", node->name, node->artist);
}

void print_list(struct songNode* front){
    struct songNode *current = front;
    while(current){
        print_node(current);
        current = current->next;
    }
}

struct songNode* findNode(struct songNode* front, char name[100], char artist[100]){
    struct songNode *current = front;
    while(current){
        if (strcmp(current->artist, artist) == 0 && strcmp(current->name, name)){
            return current;
        }
        current = current->next;
    }
    return NULL;
}