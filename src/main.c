#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "heart.h"
#include "heart_data.h"

#define USECONDS        1e6
#define DELAY           (USECONDS/10)
#define ANIMATE_SECONDS 30
#define ANIMATE_FRAMES  (ANIMATE_SECONDS*USECONDS/DELAY)

// clear the screen
void clear() {
	fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
}

// reset the color
void reset() {
	fputs("\033[0m", stdout);
	fflush(stdout); // might be called as the final write
}

int main() {

	struct heart_state state = (struct heart_state){
		.stripe_start = 0,
		.stripe_width = 8,
		.img = &heart_data,
	};

	// Reset the color to be sensitive to Ctrl-C
	atexit(reset);

	for (;state.stripe_start < ANIMATE_FRAMES; state.stripe_start++) {
		// Sleep to let the user see this frame, then clear it and draw again
		usleep(DELAY);
		clear();
		print_heart(&state);
		printf("\n\t\tC O N G R A D U L A T I O N S !!!\n");
	}

	putchar('\n');

	return 0;
}
