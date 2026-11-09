#include "VideoCapture.h"
#include "stdafx.h"

#include <pdh.h>

void exceptionAssert(bool expr, const std::string& message) {
    if (! expr) {
        throw message;
    }
}

static void DIBtoRGBA(const uint8* in, uint8* out, int width, int height) {
    // TODO: run loops backwards, start pointers at the end
    // MMX and use #ifdef
    const Color4uint8* src = reinterpret_cast<const Color4uint8*>(in);
    Color4uint8* dst = reinterpret_cast<Color4uint8*>(out);
    
    for (int y = 0; y < height; ++y) {
        Color4uint8* row = dst + (height - y - 1) * width;
        for (int x = 0; x < width; ++x) {
            // fix channels
            Color4uint8& d = *(row + x);
            d.r = src->b;
            d.g = src->g;
            d.b = src->r;
            ++src;
        }
    }
}

Array<std::string> VideoCapture::enumerateDeviceNames() {
    ICreateDevEnum *pDevEnum = NULL;
    IEnumMoniker *pEnum = NULL;
    Array<std::string> names;

	CoInitialize(NULL);

    // Create the System Device Enumerator.
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
        CLSCTX_INPROC_SERVER, IID_ICreateDevEnum, 
        reinterpret_cast<void**>(&pDevEnum));
    exceptionAssert(SUCCEEDED(hr), "Could not create SystemDeviceEnum instance");
    // Create an enumerator for the video capture category.
    hr = pDevEnum->CreateClassEnumerator(
        CLSID_VideoInputDeviceCategory,
        &pEnum, 0);
    IMoniker *pMoniker = NULL;

	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag, 
			(void**)(&pPropBag));
		if (FAILED(hr))
		{
			pMoniker->Release();
			continue;  // Skip this one, maybe the next one will work.
		} 
		// Find the description or friendly name.
		VARIANT varName;
		VariantInit(&varName);
		hr = pPropBag->Read(L"Description", &varName, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &varName, 0);
		}
        exceptionAssert(SUCCEEDED(hr), "Could not read Description or FriendlyName");
	
		USES_CONVERSION;
		names.append(OLE2T(varName.bstrVal));
		VariantClear(&varName); 
		pPropBag->Release();
		pMoniker->Release();
	}

    return names;
}

void VideoCapture::init(
       const std::string&  deviceName,
       int                 desiredWidth,
       int                 desiredHeight,
       double              desiredFrameRate) {

    CoInitialize(NULL);
    img = NULL;
    initBuilders();
	findDevice(deviceName);
	setDisplayMode(desiredWidth, desiredHeight, desiredFrameRate, MEDIASUBTYPE_RGB24);
    prepareCapture();
}

void VideoCapture::setDisplayMode( int			desiredWidth,
								   int          desiredHeight,
								   double       desiredFrameRate,
								   MediaSubtype desiredFormat) {
	debugAssert(pCap);
    debugAssert(pBuilder);
    IAMStreamConfig *pConfig = NULL;
    HRESULT hr;
    hr = pBuilder->FindInterface(
        &PIN_CATEGORY_CAPTURE, // Preview pin.
        NULL,    // Any media type.
        pCap, // Pointer to the capture filter.
        IID_IAMStreamConfig, (void**)&pConfig);

    exceptionAssert(SUCCEEDED(hr), "Could not get the preview pin interface.");

    int iCount = 0, iSize = 0;
    hr = pConfig->GetNumberOfCapabilities(&iCount, &iSize);
    exceptionAssert(SUCCEEDED(hr), "Couldn't GetNumberOfCapabilities()");
    // Check the size to make sure we pass in the correct structure.
    if (iSize == sizeof(VIDEO_STREAM_CONFIG_CAPS))
    {
        // Use the video capabilities structure.
        bool done = false;

        for (int iFormat = 0; iFormat < iCount && ! done; iFormat++)
        {
            VIDEO_STREAM_CONFIG_CAPS scc;
            AM_MEDIA_TYPE *pmtConfig;
            hr = pConfig->GetStreamCaps(iFormat, &pmtConfig, (BYTE*)&scc);
            if (SUCCEEDED(hr))
            {
                /* Examine the format, and possibly use it. */
                if ((pmtConfig->majortype == MEDIATYPE_Video) &&
                    (pmtConfig->formattype == FORMAT_VideoInfo) &&
                    (pmtConfig->cbFormat >= sizeof (VIDEOINFOHEADER)) &&
                    (pmtConfig->pbFormat != NULL)) {             
                    if ((pmtConfig->subtype == desiredFormat) &&
                        (scc.InputSize.cx == desiredWidth) &&
                        (scc.InputSize.cy == desiredHeight)) {
                        VIDEOINFOHEADER *pVih = (VIDEOINFOHEADER*)pmtConfig->pbFormat;
                        pVih->bmiHeader.biWidth = scc.InputSize.cx;
                        pVih->bmiHeader.biHeight = scc.InputSize.cy;
                        pVih->bmiHeader.biSizeImage = DIBSIZE(pVih->bmiHeader);
                        pVih->AvgTimePerFrame = scc.MinFrameInterval;
                        HRESULT hr = pConfig->SetFormat(pmtConfig);
                        /*
                        VFW_E_INVALIDMEDIATYPE 0x80040200 512  
    The specified media type is invalid.  
*/
                        exceptionAssert(hr != VFW_E_INVALIDMEDIATYPE, "Media type was invalid.");
                        exceptionAssert(SUCCEEDED(hr), "Could not SetFormat()");

                        done = true;
                    }
                }
                // Delete the media type when you are done.
                DeleteMediaType(pmtConfig);
            }
        }
        exceptionAssert(done, "Could not find a suitable display mode for the specified parameters.");
    }
}

void VideoCapture::prepareCapture() {
	HRESULT hr = pBuilder->RenderStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video, 
            pCap, NULL, renderer);
    
    exceptionAssert(SUCCEEDED(hr), "Could not RenderStream()");
    hr = renderer->QueryInterface(IID_IBasicVideo, (LPVOID *) &bv);
    debugAssertM(SUCCEEDED(hr), "Could not get IBasicVideo interface");
    hr = renderer->QueryInterface(IID_IVideoWindow, (LPVOID *)&vwnd);
    vwnd->put_AutoShow(OAFALSE); // show the video window?
    debugAssertM(SUCCEEDED(hr), "Could not get IVideoWindow interface");
    // Run the graph.
    REFERENCE_TIME start = NULL, end = MAX_TIME_VALUE;
    hr = pBuilder->ControlStream(&PIN_CATEGORY_PREVIEW, &MEDIATYPE_Video,
        pCap, &start, &end, 0, 0);
    exceptionAssert(SUCCEEDED(hr), "Could not ControlStream()");
	pControl = new CComQIPtr<IMediaControl>(pGraph);
    pEvent = new CComQIPtr<IMediaEventEx>(pGraph);
    exceptionAssert(SUCCEEDED((*pControl)->Run()), "Could not Run()");
}


void VideoCapture::endCapture() {
	(*pControl)->Stop();
	delete pControl;
	delete pEvent;
}

void VideoCapture::captureFrame() {
	if (img == NULL) {
        HRESULT r = bv->GetCurrentImage(&bufsize, NULL);
        img = new unsigned char[bufsize];
    }

    // The image is supposed to be a DIB (BITMAPINFO).  It should have
    // a BITMAPINFOHEADER followed by a pointer to the bits
    HRESULT r = bv->GetCurrentImage(&bufsize, (long*)img);
    dib = reinterpret_cast<LPBITMAPINFO>(img);
}

const uint8* VideoCapture::image() const {
	return reinterpret_cast<uint8*>(dib->bmiColors);
}


const uint32* VideoCapture::image32() const {
	return reinterpret_cast<uint32*>(dib->bmiColors);
}

void VideoCapture::getGImage(GImage& im) const {
    im.resize(width(), height(), 4);
    DIBtoRGBA(image(), im.byte(), width(), height());
}

const int VideoCapture::width() const {
    return dib->bmiHeader.biWidth;
}

const int VideoCapture::height() const {
    return dib->bmiHeader.biHeight;
}

VideoCapture::~VideoCapture() {
	endCapture();
}

void VideoCapture::initFilters(IMoniker *pMoniker) {
	initBaseFilter(pMoniker, &pCap);
	HRESULT hr = CoCreateInstance(CLSID_VideoMixingRenderer9, NULL, CLSCTX_INPROC_SERVER, IID_IBaseFilter, (LPVOID *)&renderer);
    exceptionAssert(SUCCEEDED(hr), "Could not create an instance of VideoMixingRenderer9");
    hr = pGraph->AddFilter(renderer, L"Video Mixing Renderer 9");
    exceptionAssert(SUCCEEDED(hr), "Could not AddFilter()");
}

void VideoCapture::findDevice(const std::string& deviceName) {
	ICreateDevEnum *pDevEnum = NULL;
    IEnumMoniker *pEnum = NULL;

    // Create the System Device Enumerator.
    HRESULT hr = CoCreateInstance(CLSID_SystemDeviceEnum, NULL,
        CLSCTX_INPROC_SERVER, IID_ICreateDevEnum, 
        reinterpret_cast<void**>(&pDevEnum));
    exceptionAssert(SUCCEEDED(hr), "Could not create SystemDeviceEnum instance.");
    // Create an enumerator for the video capture category.
    hr = pDevEnum->CreateClassEnumerator(
        CLSID_VideoInputDeviceCategory,
        &pEnum, 0);
    exceptionAssert(SUCCEEDED(hr), "Could not CreateClassEnumerator()");
    IMoniker *pMoniker = NULL;
	while (pEnum->Next(1, &pMoniker, NULL) == S_OK)
	{
		IPropertyBag *pPropBag;
		hr = pMoniker->BindToStorage(0, 0, IID_IPropertyBag, 
			(void**)(&pPropBag));
		if (FAILED(hr))
		{
			pMoniker->Release();
			continue;  // Skip this one, maybe the next one will work.
		} 
		// Find the description or friendly name.
		VARIANT varName;
		VariantInit(&varName);
		hr = pPropBag->Read(L"Description", &varName, 0);
		if (FAILED(hr))
		{
			hr = pPropBag->Read(L"FriendlyName", &varName, 0);
		}
		exceptionAssert(SUCCEEDED(hr), "Could not read Description or FriendlyName.");
		USES_CONVERSION;
		if (deviceName == OLE2T(varName.bstrVal)) {
			initFilters(pMoniker);
		}
		//callback(OLE2T(varName.bstrVal), pMoniker);
		VariantClear(&varName); 
		pPropBag->Release();
		pMoniker->Release();
	}
}

void VideoCapture::initBaseFilter(IMoniker* pMoniker, IBaseFilter** ppCap) {
	IBaseFilter *pCap;
    HRESULT hr = pMoniker->BindToObject(0, 0, IID_IBaseFilter, (void**)&pCap);
    exceptionAssert(SUCCEEDED(hr), "Could not BindToObject()");
    hr = pGraph->AddFilter(pCap, L"Capture Filter");
    exceptionAssert(SUCCEEDED(hr), "Could not AddFilter()");
    *ppCap = pCap;
}

void VideoCapture::initBuilders() {
	// Create the Capture Graph Builder.
    HRESULT hr = CoCreateInstance(CLSID_CaptureGraphBuilder2, NULL, 
        CLSCTX_INPROC_SERVER, IID_ICaptureGraphBuilder2, (void**)&pBuilder);
    if (SUCCEEDED(hr))
    {
        // Create the Filter Graph Manager.
        hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
            IID_IGraphBuilder, (void**)&pGraph);
        exceptionAssert(SUCCEEDED(hr), "Could not create FilterGraph instance.");
        // Initialize the Capture Graph Builder.
        pBuilder->SetFiltergraph(pGraph);
    }
}
