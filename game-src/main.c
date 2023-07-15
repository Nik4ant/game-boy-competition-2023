#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "config.h"
#include "assets/TILE_EMPTY.h"
#include "assets/TILES_NUMBERS.h"


void main()
{
	printf("Hello world!");
	printf("Game boy resolution is: %dx%d", SCREEN_SIZE[0], SCREEN_SIZE[1]);

	// set_bkg_data(0, 1, TILE_EMPTY);
	set_bkg_data(0, 10, TILES_NUMBERS);
	init_bkg(0);

	// TODO: look at game examples in the gbdk repo to see how they render colors
	SHOW_BKG;
	DISPLAY_ON;

	// Gameloop
	while (true) {
		uint8_t input = joypad();

		// scroll_bkg(1, 1);

		// delay(200);
		// Done processing, yield CPU and wait for start of next frame
		wait_vbl_done();
	}
}