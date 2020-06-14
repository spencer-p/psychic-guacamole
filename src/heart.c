#include "heart.h"

#include <stdio.h>

#define ON_PX "##"
#define OFF_PX "  "

const char *COLORS[] = {
	"\033[31m", // Red
	"\033[33m", // Yellow
	"\033[32m", // Green
	"\033[36m", // Cyan
	"\033[34m", // Blue
	"\033[35m", // Magenta
	// "\033[30m", // Black
	// "\033[37m", // White
	// "\033[0m", // Reset
};

#define COLORS_LEN (sizeof(COLORS)/sizeof(COLORS[0]))

static const char *get_color(struct heart_state *state, uint32_t i, uint32_t j) {
	// need signed arithmetic here
	ssize_t x = i;
	ssize_t y = j;
	ssize_t offset = -state->stripe_start;

	return COLORS[((x+y+offset)/4) % COLORS_LEN];
}

void print_heart(struct heart_state *state) {
	for (uint32_t i = 0; i < state->img->width; i++) {
		for (uint32_t j = 0; j < state->img->height; j++) {
			if (gimg_on(state->img, i, j)) {
				fputs(get_color(state, i, j), stdout);
				fputs(ON_PX, stdout);
			} else {
				fputs(OFF_PX, stdout);
			}

		}
		putchar('\n');
	}
}
