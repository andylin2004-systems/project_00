struct songNode* library[27];
struct songNode *createNode(char name[100], char artist[100]);
void allocateSongs();
int whereInArray(char artist[100]);
void addSong(struct songNode* song);
struct songNode* findSongByNameAndArtist(char name[100], char artist[100]);
struct songNode* findSongByArtist(char artist[100]);
void printSongListByAlphabet(char letter);
void printSongByArtist(char artist[100]);
void printLibrary();
void shuffle(int count);
void deleteSong(char name[100], char artist[100]);
void clearLibrary();