#include <stdio.h>
#include <unistd.h>

#include "heart.h"
#include "heart_data.h"

#define USECONDS 1e6
#define DELAY (USECONDS/10)
#define TIMES (5*USECONDS/DELAY)

// total_frames = 5 seconds * frame/second

// reset terminal
void clear() {
	fputs("\x1b\x63\x1b\x5b\x3f\x31\x30\x30\x30\x6c\x1b\x5b\x3f\x32\x35\x68", stdout);
}

int main() {

	struct heart_state state = (struct heart_state){
		.stripe_start = 0,
		.img = &heart_data,
	};

	for (; state.stripe_start < TIMES; state.stripe_start++) {
		usleep(DELAY);
		clear();
		print_heart(&state);
		printf("\n\t\tC O N G R A D U L A T I O N S !!!\n");
	}

	putchar('\n');

	return 0;
}
