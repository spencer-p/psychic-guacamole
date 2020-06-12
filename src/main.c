#include <stdio.h>

#include "heart.h"
#include "heart_data.h"

int main() {

	struct heart_state state = (struct heart_state){
		.diagonal = true,
		.stripe_start = 0,
		.size = 16,
	};

	print_heart(&state);

	putchar('\n');

	gimg_print_on(&heart_data);

	return 0;
}
