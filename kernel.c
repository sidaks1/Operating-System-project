# define VIDEO_MEMORY 0xB8000
# define WHITE_ON_BLACK 0x0F
#define MAX_TASKS 256
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define white_on_black 0x0F
#define LightGreyOnBlack 0x07


void clear_screen() {
    char* video_memory = (char*) VIDEO_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        video_memory[i * 2] = '\0'; // Character
        video_memory[i * 2 + 1] = white_on_black; // Color
    }
}

void kmain() {
    // Initialize the kernel
    init_kernel();

    // Enter the main loop
    while (1) {
        
        perform_kernel_tasks();
    }
}