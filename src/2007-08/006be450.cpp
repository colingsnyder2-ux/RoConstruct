// from server: 12% by colin
struct CRect {
    int left;
    int top;
    int right;
    int bottom;
};

struct CPoint {
    int x;
    int y;
};

struct CSize {
    int cx;
    int cy;
};

struct CXTPControlGalleryOffice2007Theme {
    int m_nTheme;
    int m_nState;
    int m_nType;
    int m_nStyle;

    void DrawScrollBar(void* pDC, CRect* pRect, int nState, int nType);
};

extern "C" {
    int __stdcall InflateRect(CRect* rect, int dx, int dy);
    int __stdcall IsRectEmpty(const CRect* rect);
    int __stdcall CopyRect(CRect* dst, const CRect* src);
}

extern "C" void* __stdcall sub_6ba7b0(void* p, const char* name);
extern "C" void __stdcall sub_70ffe0(void* p, int a, int b, void* out);
extern "C" void __stdcall sub_70f8a0(void* p, void* a, void* b, void* c);
extern "C" void __stdcall sub_710520(void* p, void* a, void* b, void* c, unsigned int color);
extern "C" void __stdcall sub_44baa0(void* p, int a, int b, int c, int d);
extern "C" void __stdcall sub_41ece0(void* p, void* a);
extern "C" void __stdcall sub_6bdd50(void* p, void* a, void* b, void* c, void* d);
extern "C" void __stdcall sub_6b4cb0(void* p, int a, int b);

void CXTPControlGalleryOffice2007Theme::DrawScrollBar(void* pDC, CRect* pRect, int nState, int nType)
{
    CRect rect;
    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;

    CRect srcRect = *pRect;

    sub_70f8a0(this, &srcRect, pDC, 0);

    int width = srcRect.right - srcRect.left;
    if (width > 10)
    {
        void* pTheme = sub_6ba7b0(this, "CONTROLGALLERYSCROLLARROWSHORIZONTALLIGHT");
        if (pTheme)
        {
            CRect arrowRect;
            sub_70ffe0(pTheme, 1, 1, &arrowRect);
            sub_70f8a0(pTheme, &arrowRect, pDC, 0);
        }
    }

    if (IsRectEmpty(&srcRect))
        return;

    if (srcRect.bottom != 0x3f)
        return;

    void* pTheme2 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLHORIZONTALLIGHT");
    if (!pTheme2)
        return;

    CRect thumbRect;
    sub_70ffe0(pTheme2, 1, 1, &thumbRect);
    sub_70f8a0(pTheme2, &thumbRect, pDC, 0);

    if (IsRectEmpty(&thumbRect))
        return;

    if (thumbRect.bottom != 0x3f)
        return;

    void* pTheme3 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLTHUMBHORIZONTAL");
    if (!pTheme3)
        return;

    CRect gripRect;
    sub_70ffe0(pTheme3, 1, 1, &gripRect);
    sub_70f8a0(pTheme3, &gripRect, pDC, 0);

    if (IsRectEmpty(&gripRect))
        return;

    if (gripRect.bottom != 0x3f)
        return;

    void* pTheme4 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLTHUMBGRIPPERHORIZONTAL");
    if (!pTheme4)
        return;

    CRect gripperRect;
    sub_70ffe0(pTheme4, 1, 1, &gripperRect);
    sub_70f8a0(pTheme4, &gripperRect, pDC, 0);

    if (IsRectEmpty(&gripperRect))
        return;

    if (gripperRect.bottom != 0x3f)
        return;

    void* pTheme5 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLARROWSHORIZONTALDARK");
    if (!pTheme5)
        return;

    CRect darkArrowRect;
    sub_70ffe0(pTheme5, 1, 1, &darkArrowRect);
    sub_70f8a0(pTheme5, &darkArrowRect, pDC, 0);

    if (IsRectEmpty(&darkArrowRect))
        return;

    if (darkArrowRect.bottom != 0x3f)
        return;

    void* pTheme6 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLHORIZONTALDARK");
    if (!pTheme6)
        return;

    CRect darkThumbRect;
    sub_70ffe0(pTheme6, 1, 1, &darkThumbRect);
    sub_70f8a0(pTheme6, &darkThumbRect, pDC, 0);

    if (IsRectEmpty(&darkThumbRect))
        return;

    if (darkThumbRect.bottom != 0x3f)
        return;

    void* pTheme7 = sub_6ba7b0(this, "CONTROLGALLERYSCROLLTHUMBGRIPPERVERTICAL");
    if (!pTheme7)
        return;

    CRect vertGripRect;
    sub_70ffe0(pTheme7, 1, 1, &vertGripRect);
    sub_70f8a0(pTheme7, &vertGripRect, pDC, 0);
}
