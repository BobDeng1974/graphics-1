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

        /* Fill everything with white */
	cairo_rectangle(cr, 100, 100,
	                      200, 200);
	//cairo_clip(cr);
	cairo_move_to(cr, 100, 100);

	cairo_surface_t *_warnIconSurf = cairo_image_surface_create_from_png("./icon_warning.png");
	cairo_set_source_surface(cr, _warnIconSurf, 0, 0);




        //cairo_set_source_rgb(cr, 1, 1, 1);
        cairo_paint(cr);

        cairo_surface_write_to_png(cairo_get_target(cr), "out.png");
        cairo_destroy(cr);
        return 0;
}




