# define VIDEO_MEMORY 0xB8000
# define WHITE_ON_BLACK 0x0F
#define MAX_TASKS 256
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define white_on_black 0x0F
#define LightGreyOnBlack 0x07


void display_str(char *str){
    char* video_memory = (char*) VIDEO_MEMORY;

    for(unsigned int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = white_on_black;
    }
}

void keyboardtest() {
    __asm__() volatile (
        "mov ah, 0\n"
        "int 0x16\n"
        "cmp al, 0\n"
    );
}


void kmain() {
    char* video_memory = (char*) VIDEO_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        video_memory[i * 2] = '\0';
        video_memory[i * 2 + 1] = white_on_black;
    }

    display_str("Hello, World!");
    
    while (1) {

    }

}