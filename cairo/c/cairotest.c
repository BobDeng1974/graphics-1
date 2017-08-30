/*
 * =====================================================================================
 *
 *       Filename:  cairotest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月31日 21时34分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <cairo.h>  
#include <unistd.h>  
#include <cairo-gl.h>

struct closure {
    EGLDisplay dpy;
    EGLContext ctx;
};

static void
cleanup (void *data)
{
    struct closure *arg = data;

    eglDestroyContext (arg->dpy, arg->ctx);
    eglMakeCurrent (arg->dpy, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
    eglTerminate (arg->dpy);

    free (arg);
}

static cairo_surface_t *
create_source_surface (int size)
{
    EGLint config_attribs[] = {
	EGL_RED_SIZE, 8,
	EGL_GREEN_SIZE, 8,
	EGL_BLUE_SIZE, 8,
	EGL_ALPHA_SIZE, 8,
	EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
#if CAIRO_HAS_GL_SURFACE
	EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
#elif CAIRO_HAS_GLESV2_SURFACE
	EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
#endif
	EGL_NONE
    };
    const EGLint ctx_attribs[] = {
#if CAIRO_HAS_GLESV2_SURFACE
	EGL_CONTEXT_CLIENT_VERSION, 2,
#endif
	EGL_NONE
    };

    struct closure *arg;
    cairo_device_t *device;
    cairo_surface_t *surface;
    EGLConfig config;
    EGLint numConfigs;
    EGLDisplay dpy;
    EGLContext ctx;
    int major, minor;

    dpy = eglGetDisplay (EGL_DEFAULT_DISPLAY);
    if (! eglInitialize (dpy, &major, &minor)) {
	return NULL;
    }

    eglChooseConfig (dpy, config_attribs, &config, 1, &numConfigs);
    if (numConfigs == 0) {
	return NULL;
    }

#if CAIRO_HAS_GL_SURFACE
    eglBindAPI (EGL_OPENGL_API);
#elif CAIRO_HAS_GLESV2_SURFACE
    eglBindAPI (EGL_OPENGL_ES_API);
#endif

   ctx = eglCreateContext (dpy, config, EGL_NO_CONTEXT,
				  ctx_attribs);
    if (ctx == EGL_NO_CONTEXT) {
	eglTerminate (dpy);
	return NULL;
    }

    arg = malloc (sizeof (struct closure));
    arg->dpy = dpy;
    arg->ctx = ctx;
    device = cairo_egl_device_create (dpy, ctx);
    if (cairo_device_set_user_data (device,
				    (cairo_user_data_key_t *) cleanup,
				    arg,
				    cleanup))
    {
	cleanup (arg);
	return NULL;
    }

    surface = cairo_gl_surface_create (device,
				       CAIRO_CONTENT_COLOR_ALPHA,
				       size, size);
    //cairo_device_destroy (device);

    return surface;
}

int  
main (int argc, char *argv[])  
{  
    cairo_surface_t *surface;  
    cairo_t *cr;  
 
   int x = 0; 
   int y = 0; 
    int width = 500;  
    int height = 500;  
    //surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);  
    surface = create_source_surface(500);
    cr = cairo_create (surface);  

    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);

        /* debug: paint whole surface magenta; no magenta should show */
        cairo_set_source_rgba(cr, 0, 0.0, 0, 1.0);
        cairo_paint(cr);

        cairo_set_source_rgba(cr, 0, 0.0, 0, 1.0);
        cairo_set_source_rgba(cr, 0.8, 0, 0, 0.8);
        cairo_rectangle(cr,
                        x + 80,
                        y + 80,
                        width - 160,
                        height - 160);
        cairo_fill(cr);
        //cairo_clip(cr);
        cairo_set_source_rgba(cr, 0, 0, 0.8, 0.8);
        cairo_arc(cr, x +  width/2, y + 80/2, 40, 0, 2*3.1415);
        cairo_fill(cr);
        cairo_set_source_rgba(cr, 0, 0, 0.8, 0.8);
        cairo_arc(cr, x +  width/2, y + 480 - 40, 40, 0, 2*3.1415);
        cairo_fill(cr);
        cairo_set_source_rgba(cr, 0, 0, 0.8, 0.8);
        cairo_arc(cr, x + 40, y + height/2, 40, 0, 2*3.1415);
        cairo_fill(cr);
        cairo_set_source_rgba(cr, 0, 0, 0.8, 0.8);
        cairo_arc(cr, x + 360 -40, y + height/2, 40, 0, 2*3.1415);
        cairo_fill(cr);
        cairo_paint(cr);


    /* Drawing code goes here */  
    cairo_set_line_width (cr, 10);  
    cairo_set_source_rgb (cr, 0, 0, 0);  
    cairo_rectangle (cr, width/4, height/4, width/2, height/2);  
    cairo_stroke (cr);  
    cairo_paint(cr);
    cairo_surface_finish(surface);


	while(1) {
		sleep(1);
	}
    /* Write output and clean up */  
    cairo_surface_write_to_png (surface, "rectangle.png");  
    cairo_destroy (cr);  
    cairo_surface_destroy (surface);  
  
    return 0;  
} 
