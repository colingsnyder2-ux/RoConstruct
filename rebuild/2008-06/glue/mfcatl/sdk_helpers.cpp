#include <atlbase.h>
#include <atlimage.h>
HRESULT (__stdcall *volatile nativeAtlQueryInterface)(void*, const ATL::_ATL_INTMAP_ENTRY*, REFIID, void**) = &ATL::AtlInternalQueryInterface;
void (ATL::CImage::*volatile nativeImageAttach)(HBITMAP, ATL::CImage::DIBOrientation) = &ATL::CImage::Attach;
