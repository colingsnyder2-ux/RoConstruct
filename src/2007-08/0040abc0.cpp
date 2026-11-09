// from server: 100% by tajop
struct MSG_ {
    void* hwnd;
    unsigned int message;
    unsigned int wParam;
    long lParam;
};

typedef void* (__stdcall *GetFocusFn)();
extern "C" GetFocusFn __imp__GetFocus;

struct CRuntimeClass_;

struct CObject_ {
    int IsKindOf(const CRuntimeClass_* pClass);
};

struct CWnd_ : CObject_ {
    static CWnd_* __stdcall FromHandlePermanent(void* hWnd);
};

struct CEdit_ {
    static CRuntimeClass_* GetThisClass();
};

struct CCommandBars_ {
    int PreTranslateFrameMessage(MSG_* pMsg);
};

struct S {
    unsigned char pad[0xf4];
    CCommandBars_* m_pCommandBars;
    int BasePreTranslateMessage(MSG_* pMsg);
    int PreTranslateMessage(MSG_* pMsg);
};

int S::PreTranslateMessage(MSG_* pMsg)
{
    if (pMsg->message >= 0x100 && pMsg->message <= 0x109 &&
        pMsg->wParam != 0xd && pMsg->wParam != 9 && pMsg->wParam != 0x1b)
    {
        CWnd_* pWnd = CWnd_::FromHandlePermanent(__imp__GetFocus());
        if (pWnd && pWnd->IsKindOf(CEdit_::GetThisClass()))
            return 0;
    }
    if (BasePreTranslateMessage(pMsg))
        return 1;
    if (m_pCommandBars && m_pCommandBars->PreTranslateFrameMessage(pMsg))
        return 1;
    return 0;
}
