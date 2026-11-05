/**
 @file Win32_Demo/main.cpp

 This demo is a Win32 only program that creates a window in which
 you can set pixels.  It also shows how to use the G3D::GImage class
 to load an image.  This should be sufficient setup to write 
 non-realtime programs like ray tracers and image processing demos.

 To run this sample program, you must have installed the Graphics3D library
 on your machine according to the instructions in the doc/index.html
 file.


 Requires:
   Windows
   Graphics3D

 @maintainer Morgan McGuire, matrix@graphics3d.com
 @created    2002-01-01
 @edited     2003-12-07
 */

#include <windows.h>
#include <graphics3D.h>
#include "Window.h"

using namespace G3D;

int WINAPI WinMain(
    HINSTANCE,
    HINSTANCE,
    char*       command_line,
    int         show_command) {


    Window app;

    try {

        G3D::GImage im("Win32_Demo/Cirrus.jpg");

        app.create("Win32 Sample Program", im.width, im.height);
        G3D::RGBtoBGRA(im.byte(), (unsigned char*)app.buffer, im.width * im.height);

    } catch (G3D::GImage::Error e) {

        error("Critical Error", e.reason, true);
        return -1;

    }

    app.run();

    return 0;

}