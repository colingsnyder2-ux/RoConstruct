// from server: 100% by atomic.potato
struct CXTPBitmapDC
{
    int* m_pDC;
    int m_hBitmap;
    int m_rect;
    CXTPBitmapDC& f(int hBitmap);
};

extern "C" int (__stdcall *SetRectEmpty)(int*);

CXTPBitmapDC& CXTPBitmapDC::f(int hBitmap)
{
    m_hBitmap = hBitmap;
    SetRectEmpty(&m_rect);
    m_pDC = 0;
    return *this;
}
