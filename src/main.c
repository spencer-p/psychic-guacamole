#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "heart.h"
#include "heart_data.h"

#define MSG_BUFSIZE            256
#define DEF_STRIPE_WIDTH       8
#define USECONDS               1e6
#define DELAY                  (USECONDS/10)
#define DEF_ANIMATE_SECONDS    30
#define ANIMATE_FRAMES(_secs)  (_secs*USECONDS/DELAY)

// clear the screen
void clear() {
	fputs("\x1b[H\x1b[2J\x1b[3J", stdout);
}

// reset the color
void reset() {
	fputs("\033[0m", stdout);
	fflush(stdout); // might be called as the final write
}

int main(int argc, char *argv[]) {

	struct heart_state state = (struct heart_state){
		.stripe_start = 0,
		.stripe_width = DEF_STRIPE_WIDTH,
		.img = &heart_data,
	};

	char msg[MSG_BUFSIZE] = "\n\t\tC O N G R A D U L A T I O N S !!!\n";
	uint32_t total_frames = ANIMATE_FRAMES(DEF_ANIMATE_SECONDS);
	int opt, total_seconds;
	while ((opt = getopt(argc, argv, "hw:t:m:")) != -1) {
		switch (opt) {
			case 'w':
				state.stripe_width = atoi(optarg);
				if (state.stripe_width <= 0) {
					fprintf(stderr, "Invalid stripe width %d, expected positive integer\n",
							state.stripe_width);
					exit(EXIT_FAILURE);
				}
				break;
			case 't':
				total_seconds = atoi(optarg);
				if (total_seconds < 0) {
					fprintf(stderr, "Invalid animation time %d, expected zero or positive # of seconds\n",
							total_seconds);
					exit(EXIT_FAILURE);
				}
				total_frames = ANIMATE_FRAMES(total_seconds);
				break;
			case 'm':
				strncpy(msg, optarg, MSG_BUFSIZE);
				break;
			case 'h':
			default:
				fprintf(stderr, "Usage: %s [-t # seconds] [-m \"message\"] [-w stripe_width]\n",
						argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	// Reset the color to be sensitive to Ctrl-C
	atexit(reset);

	// Animate for the total number of frames.
	// Unless the user asked for zero frames, which we treat as infinite.
	for (; total_frames == 0 || state.stripe_start < total_frames; state.stripe_start++) {
		// Sleep to let the user see this frame, then clear it and draw again
		usleep(DELAY);
		clear();
		print_heart(&state);
		fputs(msg, stdout);
		fflush(stdout); // user message might not have a newline
	}

	putchar('\n');

	return 0;
}
