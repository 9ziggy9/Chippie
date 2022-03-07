#include "../include/chip8screen.h"
#include <assert.h>
#include <unistd.h>

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

bool draw_sprite(int x, int y, const unsigned char* sprite,
		 int num_bytes, Chip8screen* screen) {
  screen_check_bounds(x,y);
  bool pixel_collision = false;
  for (int dy = 0; dy < num_bytes; dy++) {
    char c = sprite[dy];
    for (int dx = 0; dx < 8; dx++) {
    /* We take a given sprite byte and for each */
    /* binary place, 0b00000001 0b00000010, etc, we */
    /* and to see if the given place is occupied. */
    /* If it is not, we continue (do not draw). */
      if ((c & (0x80 >> dx)) == 0)
	continue;
      if (screen->pixels
	    [(dy+y) % CHIP8_DISPLAY_HEIGHT]
	    [(dx+x) % CHIP8_DISPLAY_WIDTH])
	pixel_collision = true;
      screen->pixels
	[(dy+y) % CHIP8_DISPLAY_HEIGHT]
	[(dx+x) % CHIP8_DISPLAY_WIDTH] ^= true;
    }
  }
  return pixel_collision;
}

void clear_sprites(Chip8screen* screen) {
  for (int y = 0; y < CHIP8_DISPLAY_HEIGHT; y++) {
    for (int x = 0; x < CHIP8_DISPLAY_WIDTH; x++) {
      screen->pixels[y][x] = false;
    }
  }
}
