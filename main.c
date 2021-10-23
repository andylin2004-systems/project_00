#include <stdio.h>
#include "myTunes.h"
#include "songNode.h"

int main(){
    struct songNode *library = allocateSongs();
    addSong(library, createNode("thunderstruck", "ac/dc"));
    addSong(library, createNode("alive", "pearl jam"));
    addSong(library, createNode("even flow", "pearl jam"));
    addSong(library, createNode("yellow ledbetter", "pearl jam"));
    addSong(library, createNode("time", "pink floyd"));
    addSong(library, createNode("paranoid android", "radiohead"));
    addSong(library, createNode("street spirit (fade out)", "radiohead"));
    addSong(library, createNode("chemical bond", "death pact"));
    addSong(library, createNode("sophie so", "hippo campus"));
    addSong(library, createNode("elephant boys", "hippo campus"));
    printf("LINKED LIST TEST\n\nTESTING PRINT_LIST");
    printLibrary(library);
}