/**
  @file Win32_Demo/Window.cpp

  Support routines for tests.
  
  @maintainer Morgan McGuire, matrix@graphics3d.com 
  @cite       Based on code by Max McGuire, mmcguire@ironlore.com
  @created 	  2002-09-09
  @edited  	  2003-01-25
    
  Copyright 2000-2003, Morgan McGuire.
  All rights reserved.
*/

#include "Window.h"
#include <time.h>

#if !defined(__MINGW32__)
#include <crtdbg.h>
#endif

bool Window::create(
    const std::string&  name,
    int                 width,
    int                 height) {
    
    WNDCLASS window_class;
    
    window_class.style         = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc   = window_proc;
    window_class.cbClsExtra    = 0; 
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = GetModuleHandle(NULL);
    window_class.hIcon         = LoadIcon(NULL, IDI_APPLICATION); 
    window_class.hCursor       = LoadCursor(NULL, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    window_class.lpszMenuName  = name.c_str(); 
    window_class.lpszClassName = "window"; 
    
    if (!RegisterClass(&window_class)) {
        return false;
    }
    
    // Add the non-client area
    int total_width  = width  + GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
    int total_height = height + GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);
    
    window = CreateWindow("window", 
        name.c_str(),
        WS_BORDER | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        (GetSystemMetrics(SM_CXSCREEN) - total_width) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - total_height) / 2,
        total_width,
        total_height,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL);
    
    if (window == NULL) {
        return false;
    }
    
    this->width = width;
    this->height = height;
    
    // Allocate the image buffer used for rendering
    buffer = (unsigned int*) calloc(width * height, sizeof(unsigned int));    
    
    bitmap_info.bmiHeader.biSize          = sizeof(BITMAPINFOHEADER);
    bitmap_info.bmiHeader.biWidth         = width;
    bitmap_info.bmiHeader.biHeight        = -height;    
    bitmap_info.bmiHeader.biPlanes        = 1;
    bitmap_info.bmiHeader.biBitCount      = 32;
    bitmap_info.bmiHeader.biCompression   = BI_RGB; 
    bitmap_info.bmiHeader.biSizeImage     = 0;
    bitmap_info.bmiHeader.biXPelsPerMeter = 1;
    bitmap_info.bmiHeader.biYPelsPerMeter = 1; 
    bitmap_info.bmiHeader.biClrUsed       = 0;
    bitmap_info.bmiHeader.biClrImportant  = 0;
    
    SetWindowLong(window, GWL_USERDATA, (LONG)this);
    ShowWindow(window, SW_SHOW);
    
    return true;
}


Window::Window() {
    buffer = NULL;
    width  = 0;
    height = 0;
}


void Window::close() {
    PostMessage(window, WM_CLOSE, 0, 0);
}


Window::~Window() {
    free(buffer);
    buffer = NULL;
}


void Window::requestRedraw() {
    SendMessage(window, BLIT_BUFFER, 0, 0);
}


void Window::run() {
    
    // main message loop
    
    hDC = GetDC(window);
    SetBkMode(hDC, TRANSPARENT);
    SetTextAlign(hDC, TA_TOP | TA_LEFT);
    SetStretchBltMode(hDC, COLORONCOLOR);
    
    while (true) {
        
        MSG message;
        
        if (GetMessage(&message, window, 0, 0)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        } else {
            return;
        }
        
    }
    
    ReleaseDC(window, hDC);
}


LRESULT WINAPI Window::window_proc(
    HWND                window,
    UINT                message,
    WPARAM              wparam,
    LPARAM              lparam) {
    
    Window* this_window = (Window*)GetWindowLong(window, GWL_USERDATA);
    
    switch (message) {
    case WM_KEYDOWN:
        PostQuitMessage(0);
        return 0;

    /*    case WM_KEYDOWN:
    this_window->keyChange(wparam, true);
    return 0;
    
      case WM_KEYUP:
      this_window->keyChange(wparam, false);
      return 0;  
        */
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
        
    case WM_DESTROY:
        this_window->window = NULL;
        break;
        
    case WM_PAINT:
        SetDIBitsToDevice(
            this_window->hDC,
            0, 
            0,
            this_window->width,
            this_window->height,   // source rectangle height
            0,        // x-coordinate of lower-left corner of source rect.
            0,        // y-coordinate of lower-left corner of source rect.
            0,        // first scan line in array
            this_window->height,   // number of scan lines
            this_window->buffer,
            &(this_window->bitmap_info),
            DIB_RGB_COLORS);  
        break;
        
    case BLIT_BUFFER:
        //this_window->redraw();
        break;
    }
    
    return DefWindowProc(window, message, wparam, lparam);    

}
