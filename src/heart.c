#include "heart.h"

#include <stdio.h>

/* https://www.desmos.com/calculator/05p6t6gj9v
 * I do not know what I am doing!
 */

#define sq(x) ((x)*(x))

static void print_heart_details(struct heart_state *state) {
	printf("struct heart_state {\n");
	printf("\t.size = %d\n", state->size);
	printf("\t.stripe_start = %d\n", state->stripe_start);
	printf("\t.diagonal = %s\n", state->diagonal?"true":"false");
	printf("}\n");
}

#if 0
static bool in_circle(int x, int y, int cx, int cy, int r) {
	/* A circle is (x-cx)^2 + (y-cy)^2 < r^2 */
	return sq(x-cx) + sq(y-cy) < sq(r);
}
#endif

static bool in_triangle(int x, int y, int size, int width, int top, int bottom) {
	/* This presumes a simple isoceles triangle with the base at the top,
	 * and the tip at the bottom.
	 */
	if (y < top || y > bottom) {
		return false;
	}

	/* Check which side of the line segment we are on.
	 * We can do this by extrapolating the line to the current
	 * x-coordianate. Then check where we are.
	 * We're going to turn it sideways and calculate x' from
	 * x' = my + b
	 *   where m = (width/2)/(bottom-top)
	 *   and b = (size-width)/2.
	 */

	int m = (width/2)/(bottom-top);
	int b = (size-width)/2;
	int yprime = (y-top);

	if (x < m * yprime + b) {
		return false;
	}

	/* Reflect the whole thing for the other side. */
	m *= -1;
	b = size - b;
	if (x > m * yprime + b) {
		return false;
	}

	/* I'm not great at math but I think this works */
	return true;
}

void print_heart(struct heart_state *state) {
	print_heart_details(state);
	for (uint32_t i = 0; i < state->size; i++) {
		for (uint32_t j = 0; j < state->size; j++) {
			if (in_triangle(j, i, state->size, 16, 0, 16)) {
				putchar('#');
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
}
