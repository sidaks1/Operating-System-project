#include "constants.h"
#include "screen.c"
#include "keyboard.c"

void display_str(char *str){
    char* video_memory = (char*) VIDEO_MEMORY;

    for(unsigned int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = white_on_black;
    }
}



void kmain() {

    display_str("Custom Shell\n");
    
    while (1) {
        unsigned char key = keyboardtest();
        if (key) {
            unsigned int row = display_character(key);
        }
        if (rownum >= VGA_HEIGHT) {
            scroll_screen();
        }

    }

}