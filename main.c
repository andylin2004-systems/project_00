#include <stdio.h>
#include "myTunes.h"
#include "songNode.h"

int main(){
    allocateSongs();
    addSong(createNode("thunderstruck", "ac/dc"));
    addSong(createNode("alive", "pearl jam"));
    addSong(createNode("even flow", "pearl jam"));
    addSong(createNode("yellow ledbetter", "pearl jam"));
    addSong(createNode("time", "pink floyd"));
    addSong(createNode("paranoid android", "radiohead"));
    addSong(createNode("street spirit (fade out)", "radiohead"));
    printf("LINKED LIST TEST\n\nTESTING PRINT_LIST");
    printLibrary();
    printf("fucc");
    print_node(library[0]);
}