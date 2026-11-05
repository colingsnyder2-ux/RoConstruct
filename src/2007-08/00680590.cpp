// from server: 100% by tester
struct CXTPControlSelector {
    int m_nUnknown0;
    void* m_pUnknown4;
    void* m_pUnknown8;
    int m_nUnknownC;
    void Set(void* p);
    void SetValue(int nValue);
};

struct CXTPBitmapDC {
    int m_nType;
    int m_hBitmap;
    int m_rect[4];
    CXTPBitmapDC* Init(int hBitmap, void* p, int nValue);
};

CXTPBitmapDC* CXTPBitmapDC::Init(int hBitmap, void* p, int nValue)
{
    m_hBitmap = hBitmap;
    m_nType = 0x7cecd8;
    m_rect[0] = 0;
    m_rect[1] = -1;
    if (p != 0)
        ((CXTPControlSelector*)this)->Set(p);
    ((CXTPControlSelector*)this)->SetValue(nValue);
    return this;
}
