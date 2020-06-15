#pragma once
#include <inttypes.h>
#include <stdbool.h>

#include "heart_data.h"

struct heart_state {
	uint32_t stripe_start;
	uint32_t stripe_width;
	const struct gimp_image *img;
};

void print_heart(struct heart_state *state);
