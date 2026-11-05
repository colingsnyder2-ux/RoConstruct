// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2
// roc-lib: xtp-11.2.2-lib-imports roc_claudeM_55bb15a72a4fb4db.cpp

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
__declspec(noinline) void __cdecl InitializeIcons(CXTPImageManager* manager)
{
    manager->RemoveIcon(0x80BB);
    SetIcon(manager, 0x80BB, "stop", 16);
    SetIcon(manager, 0x80BB, "stop", 32);

    manager->RemoveIcon(0x80BD);
    SetIcon(manager, 0x80BD, "home_brown", 16);
    SetIcon(manager, 0x80BD, "home_brown", 32);

    manager->RemoveIcon(0x80BC);
    SetIcon(manager, 0x80BC, "refresh_doc", 16);
    SetIcon(manager, 0x80BC, "refresh_doc", 32);

    manager->RemoveIcon(0x80BA);
    SetIcon(manager, 0x80BA, "arrowleft_green", 16);
    SetIcon(manager, 0x80BA, "arrowleft_green", 32);

    manager->RemoveIcon(0x80B9);
    SetIcon(manager, 0x80B9, "arrowright_green", 16);
    SetIcon(manager, 0x80B9, "arrowright_green", 32);
}

void __cdecl InitializeAllIcons(CXTPImageManager* manager)
{
    InitializeIcons(manager);

    manager->RemoveIcon(0xE100);
    SetIcon(manager, 0xE100, "new_document", 16);
    SetIcon(manager, 0xE100, "new_document", 32);

    manager->RemoveIcon(0xE101);
    SetIcon(manager, 0xE101, "open_document", 16);
    SetIcon(manager, 0xE101, "open_document", 32);

    manager->RemoveIcon(0xE103);
    SetIcon(manager, 0xE103, "save", 16);
    SetIcon(manager, 0xE103, "save", 32);

    manager->RemoveIcon(0xE12B);
    SetIcon(manager, 0xE12B, "undo", 16);
    SetIcon(manager, 0xE12B, "undo", 32);

    manager->RemoveIcon(0xE12C);
    SetIcon(manager, 0xE12C, "redo", 16);
    SetIcon(manager, 0xE12C, "redo", 32);

    manager->RemoveIcon(0xE120);
    SetIcon(manager, 0xE120, "delete_x", 16);
    SetIcon(manager, 0xE120, "delete_x", 32);

    manager->RemoveIcon(0xE122);
    SetIcon(manager, 0xE122, "copy_clipboard", 16);
    SetIcon(manager, 0xE122, "copy_clipboard", 32);

    manager->RemoveIcon(0xE123);
    SetIcon(manager, 0xE123, "cut_clipboard", 16);
    SetIcon(manager, 0xE123, "cut_clipboard", 32);

    manager->RemoveIcon(0xE125);
    SetIcon(manager, 0xE125, "paste_clipboard", 16);
    SetIcon(manager, 0xE125, "paste_clipboard", 32);

    manager->RemoveIcon(0x8040);
    SetIcon(manager, 0x8040, "paintcan", 16);
    SetIcon(manager, 0x8040, "paintcan", 32);

    manager->RemoveIcon(0x8073);
    SetIcon(manager, 0x8073, "lock", 16);
    SetIcon(manager, 0x8073, "lock", 32);

    manager->RemoveIcon(0x8010);
    SetIcon(manager, 0x8010, "lock", 16);
    SetIcon(manager, 0x8010, "lock", 32);

    manager->RemoveIcon(0x8011);
    SetIcon(manager, 0x8011, "lock_open", 16);
    SetIcon(manager, 0x8011, "lock_open", 32);

    manager->RemoveIcon(0x80DA);
    SetIcon(manager, 0x80DA, "recycle", 16);
    SetIcon(manager, 0x80DA, "recycle", 32);

    manager->RemoveIcon(0x80F1);
    SetIcon(manager, 0x80F1, "script_go", 16);
    SetIcon(manager, 0x80F1, "script_go", 32);

    manager->RemoveIcon(0x80F3);
    SetIcon(manager, 0x80F3, "report", 16);
    SetIcon(manager, 0x80F3, "report", 32);

    manager->RemoveIcon(0x800F);
    SetIcon(manager, 0x800F, "table", 16);
    SetIcon(manager, 0x800F, "table", 32);

    manager->RemoveIcon(0x80E2);
    SetIcon(manager, 0x80E2, "text_list_numbers", 16);
    SetIcon(manager, 0x80E2, "text_list_numbers", 32);

    manager->RemoveIcon(0x80BF);
    SetIcon(manager, 0x80BF, "world", 16);
    SetIcon(manager, 0x80BF, "world", 32);

    manager->RemoveIcon(0x8101);
    SetIcon(manager, 0x8101, "bug_error", 16);
    SetIcon(manager, 0x8101, "bug_error", 32);

    manager->RemoveIcon(0x8100);
    SetIcon(manager, 0x8100, "shield", 16);
    SetIcon(manager, 0x8100, "shield", 32);

    manager->RemoveIcon(0x803A);
    SetIcon(manager, 0x803A, "ungroup", 16);
    SetIcon(manager, 0x803A, "ungroup", 32);

    manager->RemoveIcon(0x8039);
    SetIcon(manager, 0x8039, "group", 16);
    SetIcon(manager, 0x8039, "group", 32);
}

