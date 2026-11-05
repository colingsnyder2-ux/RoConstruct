// from server: 15% by atomic.potato
// roc 2011-06 008eadb0  unit: CXTColorLum  size: 1004 bytes

struct CRect {
    int left;
    int top;
    int right;
    int bottom;
};

struct CXTColorLum {
    char pad0[4];
    void* m_hdc;
    char pad8[0x18];
    void* m_pWnd;
    char pad24[0x50];
    int m_nLum;
    char pad78[0x10];
    int m_nBarWidth;
    int DrawBar(int x, int y, int w, int h);
    void GetLumBarRect(CRect* rc);
    void Draw();
};

extern "C" {
    int __stdcall GetClientRect(void* hWnd, CRect* rc);
    int __stdcall SetPixel(void* hdc, int x, int y, unsigned int color);
    void* __stdcall GetDC(void* hWnd);
    int __stdcall ReleaseDC(void* hWnd, void* hdc);
}

void CXTColorLum::Draw()
{
    CRect rc;
    GetClientRect(m_pWnd, &rc);
    int x = rc.left + 0x11;
    int y = m_nLum;
    CRect bar;
    GetLumBarRect(&bar);
    if (bar.left > y) y = bar.left;
    if (bar.right < y) y = bar.right;
    int w = x + 7;
    int h = y - 4;
    DrawBar(w, h, 0, 0);
    DrawBar(x + 9, h, 0, 0);
    DrawBar(x + 5, y - 3, 0, 0);
    DrawBar(x + 9, y - 3, 0, 0);
    DrawBar(x + 3, y - 2, 0, 0);
    DrawBar(x + 9, y - 2, 0, 0);
    DrawBar(x + 1, y - 1, 0, 0);
    DrawBar(x + 9, y - 1, 0, 0);
    DrawBar(x, y, 0, 0);
    DrawBar(x + 9, y, 0, 0);
    DrawBar(x + 2, y + 1, 0, 0);
    DrawBar(x + 9, y + 1, 0, 0);
    DrawBar(x + 4, y + 2, 0, 0);
    DrawBar(x + 9, y + 2, 0, 0);
    DrawBar(x + 6, y + 3, 0, 0);
    DrawBar(x + 9, y + 3, 0, 0);
    DrawBar(x + 8, y + 4, 0, 0);
    DrawBar(x + 9, y + 4, 0, 0);
}
