// from server: 100% by colin
// roc 2007-08 0045ec20  unit: Scintilla::CScintillaView  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045ec20

struct RECT {
    int left;
    int top;
    int right;
    int bottom;
};

extern "C" int (__stdcall *GetClientRect)(void* hWnd, RECT* lpRect);

struct CScintillaView {
    char pad[0x20];
    void* m_hWnd;
    char pad2[0x58 - 0x24];
    void sub_63023e();
    void sub_630034(int, int, int, int, int);
    void func(int, int, int);
};

void CScintillaView::func(int a, int b, int c)
{
    RECT rc;
    sub_63023e();
    GetClientRect(m_hWnd, &rc);
    ((CScintillaView*)((char*)this + 0x58))->sub_630034(rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top, 1);
}
