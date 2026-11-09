#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include "StdAfx.h"
#include <G3DAll.h>

#include <atlbase.h>
#include <atlconv.h>

// C:\Program Files\Microsoft Visual Studio\directx\SDK (C++)\Samples\C++\DirectShow\BaseClasses
// put that on your include path for project.
#include <Streams.h>
//#include <d3d9types.h>
//#include <dshow.h>

/**
  * G3D VIDEO CAPTURE LIBRARY
  * Requires DirectShow, tested with version 9
  */
class VideoCapture {
public:
   /** A pixel format */
   typedef GUID            MediaSubtype;
private:
   IGraphBuilder* pGraph;
   ICaptureGraphBuilder2* pBuilder;
   IBaseFilter* renderer;
   IBaseFilter* pCap;
   IBasicVideo* bv;
   IVideoWindow* vwnd;
   unsigned char* img;
   long bufsize;
   LPBITMAPINFO dib;
   CComQIPtr<IMediaControl>* pControl;
   CComQIPtr<IMediaEventEx>* pEvent;

   void initBuilders();
   void findDevice(const std::string& deviceName);
   void initFilters(IMoniker *pMoniker);
   void initBaseFilter(IMoniker *pMoniker, IBaseFilter **ppCap);
   void setDisplayMode(int			desiredWidth,
					   int          desiredHeight,
				       double       desiredFrameRate = 60,
					   MediaSubtype desiredFormat    = MEDIASUBTYPE_RGB24);
   void prepareCapture();
   void endCapture();
   static const char* mediaSubypeToString(const MediaSubtype& t);

public:

   /**
    Fetches an Array<std::string> of all camera device names that we can use.
    */
   static Array<std::string> enumerateDeviceNames();

   /**
    Matches the desired width, height, frame rate, and format as closely 
    as possible.  When it cannot be matched exactly, the format is selected
    first, then the closest size and frame rate are selected.
    */
   void init(
       const std::string&  deviceName,
       int                 desiredWidth,
       int                 desiredHeight,
       double              desiredFrameRate = 60);

   ~VideoCapture();

   /** Captures the next frame of video,
       which can then be read from image */
   void captureFrame();

   /**
    Returns the width of the last frame captured. You _must_ captureFrame() before
    calling.
    */
   const int width() const;

   /**
    Returns the height of the last frame captured. You _must_ captureFrame() before
    calling.
    */
   const int height() const;

   double frameRate() const;

   MediaSubtype format() const;

   /** The frame buffer for the current image. */
   const uint8* image() const;

   /**
    The frame buffer for the current image.
    Image is in the Windows DIB format.
    */
   const uint32* image32() const;

   /**
    Returns an RGBA GImage of the current frame buffer.
    */
   void getGImage(GImage& im) const;
};

#endif