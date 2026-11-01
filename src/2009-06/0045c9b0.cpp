// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct tagRECT { long left, top, right, bottom; };
typedef tagRECT RECT;
extern "C" __declspec(dllimport) int __stdcall CopyRect(RECT*, const RECT*);
extern "C" __declspec(dllimport) int __stdcall IsRectEmpty(const RECT*);
struct PAINTSTRUCT { void* hdc; int fErase; RECT rcPaint; int fRestore; int fIncUpdate; unsigned char rgbReserved[32]; };
class CWnd { public: virtual ~CWnd(); };
class CDC { public: virtual ~CDC(); void* m_hDC; void* m_hAttribDC; int m_bPrinting; };
class CPaintDC : public CDC {
public:
    explicit CPaintDC(CWnd* pWnd);
    virtual ~CPaintDC();
    void* m_hWnd;
    PAINTSTRUCT m_ps;
};
class CRect : public tagRECT {
public:
    CRect(const RECT& srcRect) throw() { ::CopyRect(this, &srcRect); }
    int IsRectEmpty() const throw() { return ::IsRectEmpty(this); }
};
class Renderer { public: void invalidate(); };
class CRobloxView : public CWnd {
public:
    char pad[0xa0 - 4];
    Renderer* renderer;
    void OnPaint();
};
void CRobloxView::OnPaint()
{
    CPaintDC dc(this);
    CRect rect(dc.m_ps.rcPaint);
    if (!rect.IsRectEmpty())
        renderer->invalidate();
}
