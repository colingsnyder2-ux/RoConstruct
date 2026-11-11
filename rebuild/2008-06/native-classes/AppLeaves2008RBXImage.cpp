// Inactive native 2008-06 RBXImage (native-headers/AppLeaves2008/RBXImage2008.h).
// >>> native-status (generated) -- do not edit >>>
// AppLeaves2008RBXImage | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src abe06bbf | roc native-status --write
#include "AppLeaves2008/RBXImage2008.h"
#include <atlbase.h>
#include <atlalloc.h>
#include <stdlib.h>

RBXImage::RBXImage() throw()
    : m_hBitmap(NULL), m_pBits(NULL), m_hDC(NULL), m_nDCRefCount(0), m_hOldBitmap(NULL), m_nWidth(0), m_nHeight(0),
      m_nPitch(0), m_nBPP(0), m_iTransparentColor(-1), m_bHasAlphaChannel(false), m_bIsDIBSection(false)
{
}

RBXImage::~RBXImage() throw()
{
    Destroy();
}

void* RBXImage::GetPixelAddress(int x, int y) throw()
{
    return LPBYTE(m_pBits) + (y * m_nPitch) + ((x * m_nBPP) / 8);
}

int RBXImage::GetWidth() const throw()
{
    return m_nWidth;
}

BOOL RBXImage::Create(int nWidth, int nHeight, int nBPP, DWORD dwFlags) throw()
{
    return CreateEx(nWidth, nHeight, nBPP, BI_RGB, NULL, dwFlags);
}

BOOL RBXImage::CreateEx(int nWidth, int nHeight, int nBPP, DWORD eCompression, const DWORD* pdwBitfields,
                        DWORD dwFlags) throw()
{
    USES_ATL_SAFE_ALLOCA;
    LPBITMAPINFO pbmi;
    HBITMAP hBitmap;

    pbmi = (LPBITMAPINFO)_ATL_SAFE_ALLOCA(sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * 256,
                                          _ATL_SAFE_ALLOCA_DEF_THRESHOLD);
    if (pbmi == NULL)
        return FALSE;

    memset(&pbmi->bmiHeader, 0, sizeof(pbmi->bmiHeader));
    pbmi->bmiHeader.biSize = sizeof(pbmi->bmiHeader);
    pbmi->bmiHeader.biWidth = nWidth;
    pbmi->bmiHeader.biHeight = nHeight;
    pbmi->bmiHeader.biPlanes = 1;
    pbmi->bmiHeader.biBitCount = USHORT(nBPP);
    pbmi->bmiHeader.biCompression = eCompression;
    if (nBPP <= 8)
    {
        memset(pbmi->bmiColors, 0, 256 * sizeof(RGBQUAD));
    }
    else
    {
        if (eCompression == BI_BITFIELDS)
        {
            memcpy(pbmi->bmiColors, pdwBitfields, 3 * sizeof(DWORD));
        }
    }

    hBitmap = ::CreateDIBSection(NULL, pbmi, DIB_RGB_COLORS, &m_pBits, NULL, 0);
    if (hBitmap == NULL)
    {
        return FALSE;
    }

    Attach(hBitmap, (nHeight < 0) ? DIBOR_TOPDOWN : DIBOR_BOTTOMUP);

    if (dwFlags & createAlphaChannel)
    {
        m_bHasAlphaChannel = true;
    }

    return TRUE;
}

void RBXImage::UpdateBitmapInfo(DIBOrientation eOrientation)
{
    DIBSECTION dibsection;
    int nBytes;

    nBytes = ::GetObject(m_hBitmap, sizeof(DIBSECTION), &dibsection);
    if (nBytes == sizeof(DIBSECTION))
    {
        m_bIsDIBSection = true;
        m_nWidth = dibsection.dsBmih.biWidth;
        m_nHeight = abs(dibsection.dsBmih.biHeight);
        m_nBPP = dibsection.dsBmih.biBitCount;
        m_nPitch = ComputePitch(m_nWidth, m_nBPP);
        m_pBits = dibsection.dsBm.bmBits;
        if (eOrientation == DIBOR_DEFAULT)
        {
            eOrientation = (dibsection.dsBmih.biHeight > 0) ? DIBOR_BOTTOMUP : DIBOR_TOPDOWN;
        }
        if (eOrientation == DIBOR_BOTTOMUP)
        {
            m_pBits = LPBYTE(m_pBits) + ((m_nHeight - 1) * m_nPitch);
            m_nPitch = -m_nPitch;
        }
    }
    else
    {
        // Non-DIBSection
        m_bIsDIBSection = false;
        m_nWidth = dibsection.dsBm.bmWidth;
        m_nHeight = dibsection.dsBm.bmHeight;
        m_nBPP = dibsection.dsBm.bmBitsPixel;
        m_nPitch = 0;
        m_pBits = 0;
    }
    m_iTransparentColor = -1;
    m_bHasAlphaChannel = false;
}
