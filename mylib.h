// Alec Fenichel

//
// Types
//

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned long vu32;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef volatile signed char vs8;
typedef volatile signed short vs16;
typedef volatile signed long vs32;


//
// Colors
//
#define OFFSET(x,y) ((y)*240+(x))
#define BLACK RGB(0,0,0)
#define WHITE RGB(31,31,31)
#define RED RGB(31,0,0)
#define GREEN RGB(0,31,0)
#define BLUE RGB(0,0,31)
#define RGB(r,g,b) ((u16)(r | (g<<5) | (b<<10)))


//
// Keys
//

#define KEY_A 0x001
#define KEY_B 0x002
#define KEY_SELECT 0x004
#define KEY_START 0x008
#define KEY_RIGHT 0x010
#define KEY_LEFT 0x020
#define KEY_UP 0x040
#define KEY_DOWN 0x080
#define KEY_R 0x100
#define KEY_L 0x200

#define KEYS *(vu16*)0x04000130

#define keyDown(k) (~KEYS & k)


//
// Video
//

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

#define MODE_0 0x0
#define MODE_1 0x1
#define MODE_2 0x2
#define MODE_3 0x3
#define MODE_4 0x4
#define MODE_5 0x5

#define BG0_ENABLE 0x100
#define BG1_ENABLE 0x200
#define BG2_ENABLE 0x400
#define BG3_ENABLE 0x800

#define videoBuffer ((u16*)0x6000000)
#define REG_DISPCNT *(u16*)0x4000000

#define SetMode(mode) REG_DISPCNT = (mode)

#define REG_VCOUNT *(vu16*)0x4000006  // Vertical control sync
#define vsync() while(REG_VCOUNT != 160)


//
// Prototypes
//

void setPixel(int x, int y, u16 color);
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
int abs (int n);