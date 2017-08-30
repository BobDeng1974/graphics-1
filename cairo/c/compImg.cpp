
#include <cairo.h>
#include <vector>
#include <stdio.h>

struct CompositeParam {
	std::vector<const char*> imgs;
	int width;
	int height;
	const char *pText;
	int textX;
	int textY;
};

struct CompositeResult {

};

int compositeImgs(CompositeParam &param, CompositeResult &result)
{
	cairo_surface_t *surf;
	int i, w, h;

	// get original img size
	surf = cairo_image_surface_create_from_png (param.imgs[0]);
	w = cairo_image_surface_get_width (surf);
	h = cairo_image_surface_get_height (surf);
	cairo_surface_destroy(surf);

	//Create the background image
	cairo_surface_t *img = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
	//Create the cairo context
	cairo_t *cr = cairo_create(img);
	//Initialize the image to black transparent
	cairo_set_source_rgba(cr, 0,0,0, 1);
	cairo_paint(cr);

	for (i=0; i<param.imgs.size();  i++) {
		printf("%s\n", param.imgs[i]);
		surf = cairo_image_surface_create_from_png(param.imgs[i]);
		cairo_set_source_surface(cr, surf, 0, 0);
		cairo_paint(cr);
		cairo_surface_destroy(surf);
	}

	cairo_select_font_face (cr, "monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size (cr, 20);
	cairo_set_source_rgb (cr, 255, 0, 0);
	cairo_move_to (cr, param.textX, param.textY);
	cairo_show_text (cr, param.pText);


	//Destroy the cairo context and/or flush the destination image
	cairo_surface_flush(img);
	cairo_destroy(cr);

	//And write the results into a new file
	cairo_surface_write_to_png(img, "result.png");

	//Be tidy and collect your trash
	cairo_surface_destroy(img);

	return 0;

}

int main()
{
	struct CompositeParam param;
	struct CompositeResult result;
	param.imgs.push_back("./10d4/radar_0_1.png");
	param.imgs.push_back("./10d4/radar_0_1_0_0.png");
	param.imgs.push_back("./10d4/radar_0_1_1_1.png");
	param.imgs.push_back("./10d4/radar_0_1_2_2.png");
	param.imgs.push_back("./10d4/radar_0_1_3_2.png");
	param.textX = 100;
	param.textY = 100;
	param.pText = "hello";
	compositeImgs(param, result);

	return 0;
}
