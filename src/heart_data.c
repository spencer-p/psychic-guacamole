#include "heart_data.h"

#include <stddef.h>
#include <stdio.h>

bool gimg_on(const struct gimp_image *img, uint32_t x, uint32_t y) {
	// index into the 2d array. width*x + y
	// TODO(spencer-p) out of bounds check
	size_t idx = (img->width * x + y) * img->bytes_per_pixel;

	if (img->bytes_per_pixel != 4) {
		// If there is no alpha field, check if it's a black pixel
		for (size_t i = 0; i < img->bytes_per_pixel; i++) {
			if (img->pixel_data[idx+i] != 0) {
				return false;
			}
		}

		// All elements of the pixel were off (implies black).
		return true;
	}

	// If there are four bytes per pixel, we will only check the alpha
	uint8_t alpha = img->pixel_data[idx+3];

	// Alpha of 0 means off. Anything else means thix pixel is on.
	return alpha != 0;
}

void gimg_print_on(const struct gimp_image *img) {
	for (size_t i = 0; i < img->width; i++) {
		for (size_t j = 0; j < img->height; j++) {
			if (gimg_on(img, i, j)) {
				fputs("##", stdout);
			} else {
				fputs("..", stdout);
			}
		}
		putchar('\n');
	}
}

const struct gimp_image heart_data = {
  32, 32, 4,
  {
	  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\000\000\000\000\000\000\000"
		  "\000\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\000\000\000\000\000\000\000\000\000"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\000\000\000"
		  "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\000\000\000\000\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000"
		  "\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000"
		  "\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000"
		  "\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377\000\000\000\377\000\000"
		  "\000\377\000\000\000\377\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377"
		  "\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377"
		  "\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\000\000\000\377"
		  "\000\000\000\377\000\000\000\377\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377"
		  "\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000"
		  "\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000\377\377\377\000",
  },
};
