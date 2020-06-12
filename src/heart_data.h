/* GIMP RGBA C-Source image dump (heart.c) */
#pragma once
#include <inttypes.h>
#include <stdbool.h>

struct gimp_image {
	uint32_t width;
	uint32_t height;
	uint32_t bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
	uint8_t pixel_data[]; /* width * height * bytes_per_pixel + 1 */
};

extern const struct gimp_image heart_data;

bool gimg_on(const struct gimp_image *img, uint32_t x, uint32_t y);
void gimg_print_on(const struct gimp_image *img);
