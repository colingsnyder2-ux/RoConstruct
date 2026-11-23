// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <afxwin.h>

// INFERRED: CRobloxWnd's real header was not provided; treat it as an opaque CWnd-derived object.
struct CRobloxWnd;

// INFERRED: the object at this+0xb8 holds a pointer (at +0xc) to an object whose
// vtable slots 3 and 4 return the surface width and height.
struct RbxSurfaceInner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getWidth();
    virtual int getHeight();
};
struct RbxSurfaceHolder {
    char pad[0xc];
    RbxSurfaceInner* inner;
};

extern "C" void __fastcall fn_0045e6c0(CRobloxWnd* self, int unusedEdx, void* arg); // CRobloxWnd::draw(void*)

static bool g_skipPaintCheck; // 0x96df64

extern "C" bool __fastcall fn_0045e7a0(CRobloxWnd* self, int unusedEdx)
{
    CWnd* wnd = reinterpret_cast<CWnd*>(self);
    RbxSurfaceHolder* holder = *reinterpret_cast<RbxSurfaceHolder**>(reinterpret_cast<char*>(self) + 0xb8);

    if (!g_skipPaintCheck) {
        bool needInvalidate = false;
        {
            CPaintDC dc(wnd);
            int left = dc.m_ps.rcPaint.left;
            int top = dc.m_ps.rcPaint.top;
            int right = dc.m_ps.rcPaint.right;
            int bottom = dc.m_ps.rcPaint.bottom;

            if (right != 0 || left != 0 || top != 0 || bottom != 0) {
                RbxSurfaceHolder* h = *reinterpret_cast<RbxSurfaceHolder**>(reinterpret_cast<char*>(self) + 0xb8);
                if ((right - left + 1) < h->inner->getWidth() ||
                    (bottom - top + 1) < h->inner->getHeight())
                {
                    h = *reinterpret_cast<RbxSurfaceHolder**>(reinterpret_cast<char*>(self) + 0xb8);
                    h->inner->getWidth();
                    h = *reinterpret_cast<RbxSurfaceHolder**>(reinterpret_cast<char*>(self) + 0xb8);
                    h->inner->getHeight();
                    needInvalidate = true;
                }
            }
        }

        if (needInvalidate) {
            CWnd* top = wnd;
            CWnd* p = CWnd::FromHandle(::GetParent(top->m_hWnd));
            while (p) {
                top = p;
                p = CWnd::FromHandle(::GetParent(top->m_hWnd));
            }
            ::InvalidateRgn(top->m_hWnd, NULL, FALSE);
            g_skipPaintCheck = true;
            return false;
        }
    } else {
        g_skipPaintCheck = false;
    }

    fn_0045e6c0(self, 0, (void*)1);
    return true;
}
