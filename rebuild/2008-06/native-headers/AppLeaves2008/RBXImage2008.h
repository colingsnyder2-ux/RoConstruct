#pragma once
// >>> native-status (generated) -- do not edit >>>
// RBXImage2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 35cac8bc | roc native-status --write
// Inactive native 2008-06 recovery: RBXImage, Roblox's copy of ATL's CImage without the GDI+ bookkeeping
// (used as a stack object by the resource-bitmap loader 0042f0a0).
#include <windows.h>

// RTTI of vtable 008157c0: RBXImage alone (no CImage base); one slot, ??_G 00442f20. Fields from the inline
// constructor 00442c90 (vptr, +4..+18 = 0, bytes +1c/+1d = 0, +20 = -1, +24..+2c = 0; no s_initGDIPlus call) and
// the destructor 00442db0 (vptr store, then CImage::Destroy/Detach: if +4 != 0 clear +4 +8 +c +10 +18 +14,
// +20 = -1, +1d +1c = false, DeleteObject). Accessors: GetPixelAddress 00442c50 (+8 + y * +14 + x * +18 / 8) and
// GetWidth 00442c80 (+0xc). Member names and semantics follow atlimage.h, whose bodies these bytes repeat. The
// original calls even the constructor and the one-line accessors out of line (0042f0a0 calls 00442c90, 00442c50,
// 00442c80), so they are ordinary members of their own translation unit; Destroy/Detach are inlined into the
// destructor.
class RBXImage
{
public:
    RBXImage() throw();            // 00442c90
    virtual ~RBXImage() throw();   // 00442db0

    void Destroy() throw()
    {
        HBITMAP hBitmap;
        if (m_hBitmap != NULL)
        {
            hBitmap = Detach();
            ::DeleteObject(hBitmap);
        }
    }
    HBITMAP Detach() throw()
    {
        HBITMAP hBitmap;
        hBitmap = m_hBitmap;
        m_hBitmap = NULL;
        m_pBits = NULL;
        m_nWidth = 0;
        m_nHeight = 0;
        m_nBPP = 0;
        m_nPitch = 0;
        m_iTransparentColor = -1;
        m_bHasAlphaChannel = false;
        m_bIsDIBSection = false;
        return hBitmap;
    }
    enum DIBOrientation { DIBOR_DEFAULT, DIBOR_TOPDOWN, DIBOR_BOTTOMUP };
    static const DWORD createAlphaChannel = 0x01;

    // 00442f70: CreateEx(nWidth, nHeight, nBPP, BI_RGB, NULL, dwFlags).
    BOOL Create(int nWidth, int nHeight, int nBPP, DWORD dwFlags = 0) throw();
    // 00442df0: the _ATL_SAFE_ALLOCA BITMAPINFO (malloc(0x430) through CAtlSafeAllocBufferManager),
    // CreateDIBSection, then the inline Attach.
    BOOL CreateEx(int nWidth, int nHeight, int nBPP, DWORD eCompression, const DWORD* pdwBitfields = NULL,
                  DWORD dwFlags = 0) throw();
    void Attach(HBITMAP hBitmap, DIBOrientation eOrientation = DIBOR_DEFAULT) throw()
    {
        m_hBitmap = hBitmap;
        UpdateBitmapInfo(eOrientation);
    }
    void UpdateBitmapInfo(DIBOrientation eOrientation);   // 00442ce0 (GetObjectA with sizeof(DIBSECTION) 0x54)
    static int ComputePitch(int nWidth, int nBPP)
    {
        return ((((nWidth * nBPP) + 31) / 32) * 4);
    }
    void* GetPixelAddress(int x, int y) throw();   // 00442c50
    int GetWidth() const throw();                   // 00442c80

private:
    HBITMAP m_hBitmap;           // +0x04
    void* m_pBits;               // +0x08
    int m_nWidth;                // +0x0c
    int m_nHeight;               // +0x10
    int m_nPitch;                // +0x14
    int m_nBPP;                  // +0x18
    bool m_bIsDIBSection;        // +0x1c
    bool m_bHasAlphaChannel;     // +0x1d
    LONG m_iTransparentColor;    // +0x20
    mutable HDC m_hDC;           // +0x24
    mutable int m_nDCRefCount;   // +0x28
    mutable HBITMAP m_hOldBitmap; // +0x2c

    friend struct RBXImageLayout;
};
