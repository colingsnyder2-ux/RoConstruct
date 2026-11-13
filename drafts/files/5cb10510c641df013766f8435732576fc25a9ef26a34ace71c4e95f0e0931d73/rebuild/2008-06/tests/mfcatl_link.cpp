#include "force_verified.h"
#include <atlbase.h>
#include <atlimage.h>
#include <cwchar>
#include <cstdio>
typedef char bstr_size[sizeof(ATL::CComBSTR)==4?1:-1];
ATL::CComBSTR& (ATL::CComBSTR::*volatile assignAnsi)(LPCSTR) = &ATL::CComBSTR::operator=;
extern HRESULT (__stdcall *volatile nativeAtlQueryInterface)(void*, const ATL::_ATL_INTMAP_ENTRY*, REFIID, void**);
BOOL (ATL::CImage::*volatile createImage)(int,int,int,DWORD,const DWORD*,DWORD) = &ATL::CImage::CreateEx;
BOOL (ATL::CImage::*volatile createSimpleImage)(int,int,int,DWORD) = &ATL::CImage::Create;
class TestUnknown : public IUnknown {
public:
    ULONG refs;
    TestUnknown() : refs(1) {}
    HRESULT __stdcall QueryInterface(REFIID,void**) { return E_NOINTERFACE; }
    ULONG __stdcall AddRef() { return ++refs; }
    ULONG __stdcall Release() { return --refs; }
};
int main() {
    ATL::CComBSTR value;
    for (int i=0;i<32;++i) {
        if (&((value.*assignAnsi)("colin"))!=&value) return 1;
        if (value.Length()!=5 || std::wcscmp(value.m_str,L"colin")) return 2;
        (value.*assignAnsi)("");
        if (value.Length()!=0) return 3;
        (value.*assignAnsi)(NULL);
        if (value.m_str!=NULL) return 4;
    }
    TestUnknown unknown;
    const ATL::_ATL_INTMAP_ENTRY entries[]={{&IID_IUnknown,0,_ATL_SIMPLEMAPENTRY},{NULL,0,NULL}};
    void* result=NULL;
    if (nativeAtlQueryInterface(&unknown,entries,IID_IUnknown,&result)!=S_OK || result!=&unknown || unknown.refs!=2) return 5;
    static_cast<IUnknown*>(result)->Release();
    if (unknown.refs!=1) return 6;
    result=&unknown;
    if (nativeAtlQueryInterface(&unknown,entries,IID_IDispatch,&result)!=E_NOINTERFACE || result!=NULL) return 7;
    if (unknown.refs!=1) return 8;
    ATL::CImage image;
    if (!(image.*createImage)(4,-3,32,BI_RGB,NULL,0)) return 9;
    if (image.GetWidth()!=4 || image.GetHeight()!=3 || image.GetBPP()!=32) return 10;
    if (image.GetPitch()!=16 || image.GetBits()==NULL) return 11;
    image.SetPixelRGB(0,0,10,20,30);
    if (image.GetPixel(0,0)!=RGB(10,20,30)) return 12;
    HBITMAP bitmap=image.Detach();
    if (bitmap==NULL || !image.IsNull()) return 13;
    if (!DeleteObject(bitmap)) return 14;
    if (!(image.*createSimpleImage)(2,2,24,0)) return 15;
    if (image.GetWidth()!=2 || image.GetHeight()!=2 || image.GetBPP()!=24 || image.GetPitch()!=-8 || image.GetBits()==NULL) return 16;
    image.SetPixelRGB(1,1,30,20,10);
    if (image.GetPixel(1,1)!=RGB(30,20,10)) return 17;
    image.Destroy();
    if (!image.IsNull()) return 18;
    std::printf("BSTR:128 checks; COM:4 checks; native CImage:10 checks passed\n");
    return 0;
}
