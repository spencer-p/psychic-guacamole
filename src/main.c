#include <stdio.h>

#include "heart.h"

int main() {

	struct heart_state state = (struct heart_state){
		.diagonal = true,
		.stripe_start = 0,
		.size = 16,
	};

	print_heart(&state);

	return 0;
}
