
# wayland ivi extension
http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Automotive_Software_Developers_Guide#Wayland.2FWeston
https://at.projects.genivi.org/wiki/display/PROJ/Wayland+IVI+Extension+Design
https://wiki.tizen.org/Wayland_ivi-shell
https://at.projects.genivi.org/wiki/display/WIE/Quick+start

# weston.ini
http://manpages.ubuntu.com/manpages/zesty/en/man5/weston.ini.5.html

# Introduction
https://en.wikipedia.org/wiki/Wayland_%28display_server_protocol%29
https://wayland.freedesktop.org/
http://events.linuxfoundation.jp/sites/events/files/slides/ALS_201407_tanibata_weston_ivi_shell_v05.pdf


# Client Programming
https://hdante.wordpress.com/2014/07/08/the-hello-wayland-tutorial/


# Wayland APIs
http://blog.csdn.net/jinzhuojun/article/details/40264449
http://blog.csdn.net/jinzhuojun/article/details/47290707
http://www.beyondcompare.cn/wayland%E4%B8%AD%E7%9A%84%E8%B7%A8%E8%BF%9B%E7%A8%8B%E8%BF%87%E7%A8%8B%E8%B0%83%E7%94%A8%E6%B5%85%E6%9E%90.html

subsurface sync/desync
http://vberger.github.io/wayland-client-rs/src/wayland_client/interfaces/subsurface.rs.html
http://wayland.freedesktop.org/docs/html/apa.html#protocol-spec-wl_subsurface
http://blog.csdn.net/jinzhuojun/article/details/40264449
http://blog.csdn.net/goodboychina/article/details/26145175
https://hackage.haskell.org/package/bindings-GLFW-3.1.1.3/src/glfw/src/wl_window.c


# graphics stack
Wayland
EGL
libdrm
DRM


opengles
EGL
window system


# drm
http://jan.newmarch.name/Wayland/DRM/
picture ==>drawn_into==> framebuffer ==shown_on==> CRTC ==control/drive==> connector ==be_plugged==> monitor
encoder: Encoders help the CRTC to convert data from a framebuffer into the right format that can be used for the chosen connector.
Remember, we can only drive one connector per CRTC.




#libdrm
http://virtuousgeek.org/blog/index.php/jbarnes/2011/10/31/writing_stanalone_programs_with_egl_and_
http://wnwolf.com/display/2012/09/05/libdrm-samples/
http://en.wikipedia.org/wiki/Direct_Rendering_Infrastructure

#plane/crtc/encoder/connector
https://www.kernel.org/doc/htmldocs/drm/drm-kms-init.html#idp7199504

# KMS
https://www.kernel.org/doc/htmldocs/drm/drm-kms-properties.html
https://wiki.archlinux.org/index.php/Kernel_mode_setting
brezillon-drm-kms.pdf




# gbm
Generic Buffer Management (GBM) is an API which provides a mechanism for allocating buffers for graphics rendering tied to Mesa. GBM is intended to be used as a native platform for EGL on drm or openwfd. The handle it creates can be used to initialize EGL and to create render target buffers.[20]

Mesa GBM is an abstraction of the graphics driver specific buffer management APIs (for instance the various libdrm_* libraries), implemented internally by calling into the Mesa GPU drivers.

For example, the Wayland compositor Weston does its rendering using OpenGL ES 2, which it initializes by calling EGL. Since the server runs on the "bare KMS driver", it uses the EGL DRM platform, which could really be called as the GBM platform, since it relies on the Mesa GBM interface.

At XDC2014, Nvidia employee Andy Ritger proposed to enhance EGL in order to replace GBM.[21]






http://jan.newmarch.name/Wayland/
http://moi.vonos.net/linux/drm-and-kms/
https://hdante.wordpress.com/2014/07/08/the-hello-wayland-tutorial/

Wayland
http://cgit.freedesktop.org/wayland/wayland/


#NV12 YV12
http://blog.sina.com.cn/s/blog_784448d601015fiv.html
http://www.csdn123.com/html/itweb/20130912/114800_114796_114779.htm
http://kallahar.com/electronics/2004_defcon/reference/yuv%20formats%20overview.pdf

#GEM
http://lwn.net/Articles/283798/


#region
http://wayland.freedesktop.org/docs/html/apa.html

https://hdante.wordpress.com/2014/07/08/the-hello-wayland-tutorial/
http://www.cnblogs.com/blfshiye/p/4303278.html
http://jylee-world.blogspot.jp/2013_12_01_archive.html
http://blog.csdn.net/goodboychina/article/details/26080693
