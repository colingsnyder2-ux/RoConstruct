// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: xtp-11.2.2-lib-imports roc_espeon_nativepngrowsourcea42c1dc54d2add70.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<atlimage.h>, <roc_espeon_nativeatlimagewidthdecl2e5804ac680a6dd9.cpp>)
#include <afxwin.h>
#include <atlimage.h>
#include "Common/XTPImageManager.h"
#include <algorithm>
#include <cstring>
#undef FreeResource
extern "C" __declspec(dllimport) BOOL WINAPI FreeResource(HGLOBAL);
// Interface subset of native G3D/GImage.h and Color4uint8.h. Layout and ctor verified by005105b0.
namespace G3D {
struct Color4uint8 { unsigned char r,g,b,a; };
class GImage {
 unsigned char* _byte;
public:
 enum Format {JPEG,BMP,TGA,PCX,ICO,PNG,PPM_ASCII,PPM,AUTODETECT,UNKNOWN};
 int width,height,channels;
 GImage(const unsigned char*,int,Format=AUTODETECT);
 virtual ~GImage();
 Color4uint8* pixel4(){return reinterpret_cast<Color4uint8*>(_byte);}
};
}
static __declspec(noinline) bool loadIcon(CXTPImageManager* manager,UINT id,const char* name,XTPImageState state) {
 HINSTANCE module=AfxFindResourceHandle(name,"PNG"); if(!module)return false;
 HRSRC resource=FindResource(module,name,"PNG"); if(!resource)return false;
 HGLOBAL data=LoadResource(module,resource);if(!data)return false;
 const unsigned char* bytes=static_cast<const unsigned char*>(LockResource(data));if(!bytes)return false;
 G3D::GImage decoded(bytes,SizeofResource(module,resource),G3D::GImage::PNG);
 for(int x=0;x<decoded.width;++x)for(int y=0;y<decoded.height;++y)std::swap(decoded.pixel4()[y*decoded.width+x].r,decoded.pixel4()[y*decoded.width+x].b);
 ATL::CImage bitmap;
 if(!bitmap.Create(decoded.width,decoded.height,decoded.channels*8,decoded.channels==4))return false;
 bitmap.GetWidth();
 G3D::Color4uint8* pixels=decoded.pixel4();
 for(int y=0;y<decoded.height;++y){ void* destination=bitmap.GetPixelAddress(0,y); const G3D::Color4uint8* row=pixels+y*decoded.width; memcpy(destination,row,decoded.width*sizeof(G3D::Color4uint8)); }
 bool ok=manager->SetIcon((HBITMAP)bitmap,id,CSize(0),state)!=FALSE;
 FreeResource(data);return ok;
}
static __declspec(noinline) void SetIcon(CXTPImageManager* manager,UINT id,const char* name,int size){
 CString text;text.Format("\"%s_%d\"",name,size);
 if(loadIcon(manager,id,text.MakeUpper(),xtpImageNormal)){
 text.Format("\"%s_%d_D\"",name,size);loadIcon(manager,id,text.MakeUpper(),xtpImageDisabled);
 text.Format("\"%s_%d_H\"",name,size);loadIcon(manager,id,text.MakeUpper(),xtpImageHot);
 }
}
void __cdecl InitializeIcons(CXTPImageManager* manager)
{
    manager->RemoveIcon(0x80BB);
    SetIcon(manager, 0x80BB, "stop", 16);
    SetIcon(manager, 0x80BB, "stop", 32);

    manager->RemoveIcon(0x80BD);
    SetIcon(manager, 0x80BD, "refresh_doc", 16);
    SetIcon(manager, 0x80BD, "refresh_doc", 32);

    manager->RemoveIcon(0x80BC);
    SetIcon(manager, 0x80BC, "home_brown", 16);
    SetIcon(manager, 0x80BC, "home_brown", 32);

    manager->RemoveIcon(0x80BA);
    SetIcon(manager, 0x80BA, "arrowleft_green", 16);
    SetIcon(manager, 0x80BA, "arrowleft_green", 32);

    manager->RemoveIcon(0x80B9);
    SetIcon(manager, 0x80B9, "arrowright_green", 16);
    SetIcon(manager, 0x80B9, "arrowright_green", 32);
}
