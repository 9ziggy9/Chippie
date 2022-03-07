#include "../include/chip8screen.h"
#include <assert.h>

static void screen_check_bounds(int x, int y) {
    assert(x >= 0 && x < CHIP8_DISPLAY_WIDTH);
    assert(y >= 0 && y < CHIP8_DISPLAY_HEIGHT);
}

void pixel_set(int x, int y, Chip8screen* screen) {
    screen_check_bounds(x,y);
    screen->pixels[y][x] = true;
}

bool pixel_is_set(int x, int y, Chip8screen* screen) {
    screen_check_bounds(x,y);
    return screen->pixels[y][x];
}

bool draw_sprite(int x, int y, const char* sprite,
		 int num_bytes, Chip8screen* screen) {
  bool pixel_collision = false;
  for (int ly = 0; ly < num_bytes; ly++) {
    char c = sprite[ly];
    for (int lx = 0; lx < 8; lx++) {
    /* We take a given sprite byte and for each */
    /* binary place, 0b00000001 0b00000010, etc, we */
    /* and to see if the given place is occupied. */
    /* If it is not, we continue (do not draw). */
      if ((c & (0x80 >> lx)) == 0) 
	continue;
    }
  }
  return pixel_collision;
}
