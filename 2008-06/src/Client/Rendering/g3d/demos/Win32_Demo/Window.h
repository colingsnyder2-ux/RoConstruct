/**
  @file Win32_Demo/Window.h

  Support routines for tests.
  
  @maintainer Morgan McGuire, matrix@graphics3d.com 
  @cite       Based on code by Max McGuire, mmcguire@ironlore.com
  @created 	  2002-09-09
  @edited  	  2002-07-02
    
  Copyright 2000-2002, Morgan McGuire.
  All rights reserved.
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include <string>
#include <time.h>

const UINT BLIT_BUFFER = 0xC001;

class Window {

public:

   Window();
   virtual ~Window();

   virtual bool create(const std::string& name, int width, int height);

   void close();
   void requestRedraw();
   void run();

   HDC                  hDC;

   int                  width;
   int                  height;

   /**
    Size width x height x 4
    */
   unsigned int*        buffer;

   /**
    Buffer bitmap info used for converting it to a DIB.
    */
   BITMAPINFO           bitmap_info;

   HWND                 window;

private:
   
   static LRESULT WINAPI window_proc(HWND window, UINT message, WPARAM wparam, LPARAM lparam);

};

#endif