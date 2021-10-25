#include <stdio.h>
#include "myTunes.h"
#include "songNode.h"

int main(){
    struct songNode *singleSong = createNode("time", "pink floyd");
    printf("adding song to a linked list (front)\n");
    singleSong = addToFront(singleSong, createNode("thunderstruck", "ac/dc"));
    printf("adding song to a linked list (alpha order) and print list\n");
    singleSong = addBasedOnAlphabet(singleSong, createNode("alive", "pearl jam"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("even flow", "pearl jam"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("yellow ledbetter", "pearl jam"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("paranoid android", "radiohead"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("street spirit (fade out)", "radiohead"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("chemical bond", "death pact"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("sophie so", "hippo campus"));
    singleSong = addBasedOnAlphabet(singleSong, createNode("elephant boys", "hippo campus"));
    print_list(singleSong);
    printf("\nprint node\n");
    print_node(singleSong);
    printf("\nfind artist\n");
    findNodeByArtist(singleSong, "hippo campus");
    printf("find node\n");
    findNodeByNameAndArtist(singleSong, "time", "pink floyd");
    printf("\ncomparing song comparing between 1st three %d\m", checkIfShouldPlaceAlphabet(singleSong, singleSong->next, singleSong->next->next));
    printf("check random\n");
    returnRandomNode(singleSong);
    returnRandomNode(singleSong);
    returnRandomNode(singleSong);
    printf("remove test\n");
    singleSong = removeNodeByNameAndArtist(singleSong,"chemical bond", "death pact");
    print_list(singleSong);
    printf("free list test\n");
    singleSong = freeList(singleSong);
    print_list(singleSong);
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
    printf("LINKED LIST TEST\n\nTESTING PRINT_LIST:\n");
    printLibrary(library);
    printf("\nFIND SONG BASED ON SONG NAME AND ARTIST TEST: \n Finding node for Chemical Bond\n");
    if (findSongByNameAndArtist(library, "chemical bond", "death pact")){
        printf("found it!");
    }else{
        printf("big oof");
    }
    printf("\nFinding node for Bambi\n");
    if (findSongByNameAndArtist(library, "bambi", "hippo campus")){
        printf("found it!");
    }else{
        printf("big oof");
    }
    printf("\nFIND ALL SONGS BY ARTIST TEST: \nFinding node for songs by Hippo Campus\n");
    printSongByArtist(library, "hippo campus");
    printf("\nFinding node for songs by Rezz\n");
    printSongByArtist(library, "rezz");
    printf("\nTESTING SHUFFLE (4 songs)");
    shuffle(library, 4);
    printf("\nTESTING REMOVE SONG");
    printf("\nRemoving sophie so by hippo campus\n");
    deleteSong(library, "sophie so", "hippo campus");
    printLibrary(library);
    printf("\nRemoving chemical bond by death pact\n");
    deleteSong(library, "chemical bond", "death pact");
    printLibrary(library);
    printf("\nFINDING SONGS BY LETTER (letter p)\n");
    printSongListByAlphabet(library, 'p');
    printf("\n(letter h)\n");
    printSongListByAlphabet(library, 'h');
    printf("\n(letter b)\n");
    printSongListByAlphabet(library, 'b');
    printf("\nclearing library\n");
    clearLibrary(library);
    printLibrary(library);
    printf("done\n");
}