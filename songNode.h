struct songNode{
    char name[100];
    char artist[100];
    struct songNode *next;
};

struct songNode *createNode(char name[100], char artist[100]);

struct songNode* addToFront(struct songNode* front, struct songNode* toAdd);

struct songNode * addBasedOnAlphabet(struct songNode* front, struct songNode* toInsert);

int checkIfShouldPlaceAlphabet(struct songNode* prev, struct songNode* toInsert, struct songNode* next);

void print_node(struct songNode* node);

void print_list(struct songNode* front);

struct songNode* findNodeByNameAndArtist(struct songNode* front, char name[100], char artist[100]);

struct songNode * findNodeByArtist(struct songNode * front, char artist[100]);

struct songNode * returnRandomNode(struct songNode * front);

struct songNode* removeNodeByNameAndArtist(struct songNode * front, char name[100], char artist[100]);

struct songNode * freeList(struct songNode *front);