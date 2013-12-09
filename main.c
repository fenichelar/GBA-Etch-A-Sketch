#include "mylib.h"

// Alec Fenichel

// This is an Etch A Sketch game. Controls are:
// Right arrow = move right
// Left arrow = move left
// Up arrow = move up
// Down arrow = move down
// A = next color
// B = previos color
// Select = reset
// Start = switch background

int main(void) {

    SetMode(MODE_3 | BG2_ENABLE);
    
    int x = 0;
    int y = 0;
    int i = 0;
    u16 color[4];
    color[0] = WHITE;
    color[1] = RED;
    color[2] = GREEN;
    color[3] = BLUE;

    setPixel(x,y,color[i]);

    while(1) {
        vsync();
        
        // Reset
        if(keyDown(KEY_SELECT)) {
            x = 0;
            y = 0;
            i = 0;
            drawRect(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
            color[0] = WHITE;
            setPixel(x,y,color[i]);
            while(keyDown(KEY_SELECT)) {

            }
        }
        
        // Switch between black and white backgrounds
        if(keyDown(KEY_START)) {
            x = 0;
            y = 0;
            i = 0;
            if(color[0] == WHITE) {
                drawRect(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, WHITE);
                color[0] = BLACK;
            } else {
                drawRect(x, y, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
                color[0] = WHITE;
            }
            setPixel(x,y,color[i]);
            while(keyDown(KEY_START)) {

            }
        }
        
        // Switch colors (A = next color, B = previous color)
        if(keyDown(KEY_A)) {
            i++;
            i = i % 4;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_A)) {

            }
        } else if(keyDown(KEY_B)) {
            i--;
            i = i % 4;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_B)) {

            }
        }
        
        // Draw with arrow keys
        if(keyDown(KEY_DOWN) && (y < SCREEN_HEIGHT)){
            y++;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_DOWN)) {

            }
        } else if(keyDown(KEY_UP) && (y > 0)) {
            y--;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_UP)) {

            }
        } else if(keyDown(KEY_RIGHT) && (x < SCREEN_HEIGHT)) {
            x++;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_RIGHT)) {

            }
        } else if(keyDown(KEY_LEFT) && (x > 0)) {
            x--;
            setPixel(x,y,color[abs(i)]);
            while(keyDown(KEY_LEFT)) {

            }
        }
    }

    return 0;
}