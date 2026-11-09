// from server: 24% by colin
// roc 2007-08 0070d4c0  unit: CXTColorLum  size: 1000 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070d4c0

struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};

struct CXTColorLum {
    char pad0[4];
    void* field4;
    char pad8[0x18];
    void* field20;
    char pad24[0x64];
    int field88;
    void OnDraw(void* hdc);
};

extern "C" {
    int __stdcall GetClientRect(void* hwnd, RECT* rect);
    int __stdcall SetPixel(void* hdc, int x, int y, unsigned int color);
}

extern int g_8c9750;

void CXTColorLum::OnDraw(void* hdc)
{
    RECT rc;
    GetClientRect(field20, &rc);
    int left = rc.left + 0x11;
    int top = field88 + 4;
    int right = rc.right - 1;
    if (top > right)
        top = right;
    int bottom = rc.bottom - 1;

    void* dc = hdc;
    (void)dc;

    int x1 = left + 7;
    int x2 = left + 9;
    int x3 = left + 5;
    int x4 = left + 3;
    int x5 = left + 1;
    int x6 = left + 2;
    int x7 = left + 4;
    int x8 = left + 6;
    int x9 = left + 8;

    int y1 = top - 4;
    int y2 = top - 3;
    int y3 = top - 2;
    int y4 = top - 1;
    int y5 = top;
    int y6 = top + 1;
    int y7 = top + 2;
    int y8 = top + 3;
    int y9 = top + 4;

    if (g_8c9750 != 2) {
        SetPixel(field4, x1, y1, 0);
        SetPixel(field4, x2, y1, 0);
        SetPixel(field4, x3, y2, 0);
        SetPixel(field4, x4, y2, 0);
        SetPixel(field4, x5, y3, 0);
        SetPixel(field4, x6, y3, 0);
        SetPixel(field4, x7, y4, 0);
        SetPixel(field4, x8, y4, 0);
        SetPixel(field4, x9, y5, 0);
        SetPixel(field4, x9, y6, 0);
        SetPixel(field4, x9, y7, 0);
        SetPixel(field4, x9, y8, 0);
        SetPixel(field4, x9, y9, 0);
        SetPixel(field4, x8, y9, 0);
        SetPixel(field4, x7, y9, 0);
        SetPixel(field4, x6, y9, 0);
        SetPixel(field4, x5, y9, 0);
        SetPixel(field4, x4, y9, 0);
        SetPixel(field4, x3, y9, 0);
        SetPixel(field4, x2, y9, 0);
        SetPixel(field4, x1, y9, 0);
        SetPixel(field4, x1, y8, 0);
        SetPixel(field4, x1, y7, 0);
        SetPixel(field4, x1, y6, 0);
        SetPixel(field4, x1, y5, 0);
        SetPixel(field4, x1, y4, 0);
        SetPixel(field4, x1, y3, 0);
        SetPixel(field4, x1, y2, 0);
        SetPixel(field4, x1, y1, 0);
    }
}
