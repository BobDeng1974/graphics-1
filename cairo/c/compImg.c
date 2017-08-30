
#include <cairo.h>

int main()
{
    //Load a few images from files
    cairo_surface_t *surf1 = cairo_image_surface_create_from_png("a.png");
    cairo_surface_t *surf2 = cairo_image_surface_create_from_png("b.png");

    //Create the background image
 //   cairo_surface_t *img = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 100, 100);
    cairo_surface_t *img = cairo_image_surface_create(CAIRO_FORMAT_RGBA32, 100, 100);

    //Create the cairo context
    cairo_t *cr = cairo_create(img);

    //Initialize the image to black transparent
    cairo_set_source_rgba(cr, 0,0,0, 1);
    cairo_paint(cr);

    //Paint one image
    cairo_set_source_surface(cr, surf1, 0, 0);
    cairo_paint(cr);

    //Paint the other image
    cairo_set_source_surface(cr, surf2, 50, 50);
    cairo_paint(cr);

            cairo_select_font_face (cr, "monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
        cairo_set_font_size (cr, 14);
        cairo_set_source_rgb (cr, 0, 0, 0);
        cairo_move_to (cr, 0, 50);
        cairo_show_text (cr, "Print Something");


    //Destroy the cairo context and/or flush the destination image
    cairo_surface_flush(img);
    cairo_destroy(cr);

    //And write the results into a new file
    cairo_surface_write_to_png(img, "result.png");

    //Be tidy and collect your trash
    cairo_surface_destroy(img);
    cairo_surface_destroy(surf1);
    cairo_surface_destroy(surf2);

    return 0;

}
