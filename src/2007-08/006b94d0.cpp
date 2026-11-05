// from server: 37% by colin
// roc 2007-08 006b94d0  unit: XTPPaintThemes::CXTPDefaultTheme  size: 424 bytes
// library rbxgs/v8world\World.cpp

extern "C" {
    typedef unsigned int DWORD;
    typedef unsigned short WORD;
    typedef unsigned char BYTE;
    typedef void* HGDIOBJ;
    typedef void* HBITMAP;
    typedef void* HBRUSH;
    typedef void* HDC;

    __declspec(dllimport) HBITMAP __stdcall CreateBitmap(int, int, unsigned int, unsigned int, const void*);
    __declspec(dllimport) HBRUSH __stdcall CreatePatternBrush(HBITMAP);
    __declspec(dllimport) int __stdcall PatBlt(HDC, int, int, int, int, DWORD);
}

struct CString {
    void* m_pData;
    CString();
    CString(const CString&);
    ~CString();
    CString& operator=(const CString&);
};

struct CPoint {
    int x;
    int y;
};

struct CRect {
    int left;
    int top;
    int right;
    int bottom;
};

struct CXTPPaintManager {
    void* m_pData;
    CString* GetResourceString(int id);
};

struct CXTPDefaultTheme {
    void* m_pData;
    void Draw3dRect(HDC hdc, CRect* pRect, int nColor1, int nColor2);
    void Draw3dRect(HDC hdc, int x, int y, int cx, int cy, int nColor1, int nColor2);
};

extern "C" void __cdecl __security_check_cookie(DWORD);
extern "C" DWORD __stdcall GetSysColor(int);

extern DWORD g_dwCookie;

void CXTPDefaultTheme::Draw3dRect(HDC hdc, CRect* pRect, int nColor1, int nColor2)
{
    CString str;
    CString str2;
    HBITMAP hBitmap;
    HBRUSH hBrush;
    HGDIOBJ hOldBrush;
    HGDIOBJ hOldBitmap;
    WORD pattern[8];
    int x, y, cx, cy;
    int savedX, savedY, savedCX, savedCY;

    pattern[0] = 0x55;
    pattern[1] = 0xaa;
    pattern[2] = 0x55;
    pattern[3] = 0xaa;
    pattern[4] = 0x55;
    pattern[5] = 0xaa;
    pattern[6] = 0x55;
    pattern[7] = 0xaa;

    hBitmap = CreateBitmap(8, 8, 1, 1, pattern);
    hBrush = CreatePatternBrush(hBitmap);

    hOldBrush = 0;
    hOldBitmap = 0;

    x = pRect->left;
    y = pRect->top;
    cx = pRect->right - pRect->left;
    cy = pRect->bottom - pRect->top;

    PatBlt(hdc, x, y, cx, cy, 0x00F00021);

    hOldBrush = 0;
    hOldBitmap = 0;
}
