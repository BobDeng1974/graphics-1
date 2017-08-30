/*
 * =====================================================================================
 *
 *       Filename:  font.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年01月21日 22时11分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cairo.h>
int main()
{
        cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 400, 400);
        cairo_t *cr = cairo_create(surface);

	int              w, h;
	cairo_surface_t *image;
	image = cairo_image_surface_create_from_png ("./icon_warning.png");
	w = cairo_image_surface_get_width (image);
	h = cairo_image_surface_get_height (image);

	//cairo_translate (cr, 128.0, 128.0);
	//cairo_rotate (cr, 45* 3.14/180);
	cairo_scale  (cr, 256.0/w, 256.0/h);
	//cairo_translate (cr, -0.5*w, -0.5*h);

	cairo_set_source_surface (cr, image, 0, 0);
	cairo_paint (cr);
	cairo_surface_destroy (image);
        cairo_surface_write_to_png(cairo_get_target(cr), "out.png");

        return 0;
}




