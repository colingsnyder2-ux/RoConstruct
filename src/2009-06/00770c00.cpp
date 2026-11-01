// from server: 100% by tester
struct CXTPBitmapDC {
    int m_nType;
    int m_hBitmap;
    int m_rect[4];
    CXTPBitmapDC* Init(int hBitmap);
};

extern "C" int (__stdcall *SetRectEmpty)(int* rect);

CXTPBitmapDC* CXTPBitmapDC::Init(int hBitmap)
{
    m_hBitmap = hBitmap;
    SetRectEmpty(m_rect);
    m_nType = 0;
    return this;
}
