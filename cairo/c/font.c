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
        cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 200, 200);
        cairo_t *cr = cairo_create(surface);
        cairo_surface_destroy(surface);

        /* Fill everything with white */
        cairo_set_source_rgb(cr, 1, 1, 1);
        cairo_paint(cr);

        /* Draw some text */
        cairo_select_font_face (cr, "monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_font_size (cr, 14);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_move_to (cr, 0, 50);
        cairo_show_text (cr, "Print Something");

        cairo_surface_write_to_png(cairo_get_target(cr), "out.png");
        cairo_destroy(cr);
        return 0;
}




