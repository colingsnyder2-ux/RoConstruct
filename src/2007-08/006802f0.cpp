// from server: 24% by colin
// roc 2007-08 006802f0  unit: CXTPBufferDC  size: 305 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006802f0

extern "C" {
    typedef void* HDC;
    typedef void* HBITMAP;
    typedef void* HGDIOBJ;
    typedef void* HRGN;
    typedef int BOOL;
    typedef unsigned int UINT;
    typedef unsigned long DWORD;
    typedef long LONG;
    typedef unsigned short WORD;

    struct RECT {
        LONG left;
        LONG top;
        LONG right;
        LONG bottom;
    };

    __declspec(dllimport) HDC __stdcall CreateCompatibleDC(HDC hdc);
    __declspec(dllimport) HBITMAP __stdcall CreateCompatibleBitmap(HDC hdc, int cx, int cy);
    __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h);
    __declspec(dllimport) HRGN __stdcall CreateRectRgnIndirect(const RECT* lprect);
    __declspec(dllimport) BOOL __stdcall CopyRect(RECT* lprcDst, const RECT* lprcSrc);
}

struct CXTPBufferDC {
    void* vtable;
    HDC m_hDC;
    HDC m_hAttribDC;
    int m_nWidth;
    int m_nHeight;
    void* m_pRgn;
    HBITMAP m_hBitmap;
    HGDIOBJ m_hOldBitmap;
    RECT m_rc;
    int m_nSavedDC;
    void* m_pBits;
    void* m_pOldBits;

    CXTPBufferDC(HDC hDC, int x, int y, int cx, int cy);
};

extern "C" void __stdcall sub_7383e2();
extern "C" void __stdcall sub_7383d0();
extern "C" void __stdcall sub_73850e();
extern "C" void __stdcall sub_630238();
extern "C" void __stdcall sub_41f680();

CXTPBufferDC::CXTPBufferDC(HDC hDC, int x, int y, int cx, int cy)
{
    sub_7383e2();
    this->vtable = (void*)0x7cec54;
    this->m_pRgn = 0;
    this->m_hBitmap = 0;
    this->m_hOldBitmap = (HGDIOBJ)0x788300;
    this->m_hAttribDC = hDC;
    this->m_hDC = CreateCompatibleDC(hDC);
    SelectObject(this->m_hDC, CreateCompatibleBitmap(this->m_hDC, cx, cy));
    sub_7383d0();
    if (this->m_hDC != 0) {
        int w = this->m_nWidth;
        int h = this->m_nHeight;
        if (w < 1) w = 1;
        if (h < 1) h = 1;
        sub_630238();
        sub_73850e();
    }
}
