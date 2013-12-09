#include "mylib.h"

// Alec Fenichel

// A function to set pixel (x, y) to the color passed in. 
void setPixel(int x, int y, u16 color) {
	videoBuffer[OFFSET(x,y)] = color;
}

// A function to draw a FILLED rectangle starting at (x, y) 
void drawRect(int x, int y, int width, int height, u16 color) {
	for (int i = x; i <= x + width; i ++) {
		for (int j = y; j <= y + height; j ++) {
			setPixel(i, j, color);
		}
	}
} 

// A function to draw a HOLLOW rectangle starting at (x, y) 
void drawHollowRect(int x, int y, int width, int height, u16 color) {
	for (int i = x; i <= x + width; i ++) {
		setPixel(i, y, color);
		setPixel(i, y + height, color);
	}
	for (int i = y; i <= y + height; i ++) {
		setPixel(x, i, color);
		setPixel(x + width, i, color);
	}
}

// Returns absolute value of integer
int abs (int n) {
    const int ret[2] = { n, -n };
    return ret [n<0];
}