#pragma once
#include <inttypes.h>
#include <stdbool.h>

struct heart_state {
	uint32_t size;
	uint16_t stripe_start;
	bool diagonal;
};

void print_heart(struct heart_state *state);
