// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 0070d990  unit: CXTColorLum  size: 308 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0070d990
// Shape: MFC PreTranslateMessage. global 0x8c9750 == 2 gate, rect getter 0x70d210 (thiscall),
// WM_KEYDOWN switch on (char)wParam: VK_RETURN/VK_SPACE -> GetParent()->GetParent()->fn_738ce8(TRUE),
// VK_UP/VK_DOWN adjust +0x84 clamped to [0, rc.bottom] then vtbl+0x14c(m_80, m_84, TRUE).
typedef void* HWND;
extern "C" __declspec(dllimport) HWND __stdcall GetParent(HWND);

struct tagMSG { HWND hwnd; unsigned int message; unsigned int wParam; long lParam; };
struct tagRECT { long left, top, right, bottom; };

#define V(n) virtual void v##n();
#define V10(a) V(a##0) V(a##1) V(a##2) V(a##3) V(a##4) V(a##5) V(a##6) V(a##7) V(a##8) V(a##9)

struct CWnd {
    V10(0) V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7)
    V(80) V(81) V(82)
    virtual void SetPos(int x, int y, int notify);   // vtbl +0x14c
    char pad[0x20 - 4];
    HWND m_hWnd;                                     // +0x20
    static CWnd* __stdcall FromHandle(HWND);         // 0x6301c0
    int PreTranslateMessage(tagMSG* pMsg);           // 0x63026e
    void fn_738ce8(int);                             // 0x738ce8
    CWnd* GetParent() { return FromHandle(::GetParent(m_hWnd)); }
};

extern int g_mode_8c9750;

struct CXTColorLum : CWnd {
    char pad2[0x80 - 0x24];
    int m_x;    // +0x80
    int m_y;    // +0x84
    void GetLumRect(tagRECT* rc);                    // 0x70d210
    int PreTranslateMessage(tagMSG* pMsg);
};

int CXTColorLum::PreTranslateMessage(tagMSG* pMsg)
{
    if (g_mode_8c9750 == 2) {
        tagRECT rc;
        GetLumRect(&rc);
        if (pMsg->message == 0x100) {
            switch ((char)pMsg->wParam) {
            case 0x26:
                if (--m_y < 0)
                    m_y = 0;
                SetPos(m_x, m_y, 1);
                return 1;
            case 0x28:
                if (++m_y > rc.bottom)
                    m_y = rc.bottom;
                SetPos(m_x, m_y, 1);
                return 1;
            case 0x0d:
            case 0x20: {
                CWnd* owner = GetParent()->GetParent();
                owner->fn_738ce8(1);
                }
                break;
            }
        }
    }
    return CWnd::PreTranslateMessage(pMsg);
}
