#include "constants.h"


int rownum = 0;
int colnum = 0;

void scroll_screen() {
    char* video_memory = (char*) VIDEO_MEMORY;
    for (int i = 0; i < (VGA_WIDTH * (VGA_HEIGHT - 1)); i++) {
        video_memory[i * 2] = video_memory[(i + VGA_WIDTH) * 2];
        video_memory[i * 2 + 1] = video_memory[(i + VGA_WIDTH) * 2 + 1];
    }
    for (int i = (VGA_WIDTH * (VGA_HEIGHT - 1)); i < VGA_WIDTH * VGA_HEIGHT; i++) {
        video_memory[i * 2] = '\0';
        video_memory[i * 2 + 1] = white_on_black;
    }
    rownum--;
}

    
void clear_screen() {
    char* video_memory = (char*) VIDEO_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        video_memory[i * 2] = '\0';
        video_memory[i * 2 + 1] = white_on_black;
    }
}


unsigned int display_character(char c){

    char* video_memory = (char*) VIDEO_MEMORY;
    unsigned int cursor = rownum * VGA_WIDTH + colnum;

    if (c == '\n') {
        colnum = 0;
        rownum++;
        return;
    }

    if (c == '\b') {
        if (colnum > 0) {
            colnum--;
        }
        return;
    }

    video_memory[cursor * 2] = c;
    video_memory[cursor * 2 + 1] = white_on_black;
    colnum++;

    if (colnum >= VGA_WIDTH) {
        colnum = 0;
        rownum++;
    }
    return rownum;
}


