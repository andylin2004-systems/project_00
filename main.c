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
}