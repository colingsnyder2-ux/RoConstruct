// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: CPoint-like by-value struct (two dwords). The original loads both halves
// into registers and re-pushes them, which is what a by-value struct forward does.
// Passing three plain ints straight through compiled to a tail-call jmp instead.
struct FnPoint00704da0 {
    int x;
    int y;
};

// INFERRED: callee is the CXTPTabClientWnd::OnLButtonDown-style helper (UINT, CPoint),
// stdcall with 12 bytes of args.
extern "C" void __stdcall fn_007048b0(unsigned int nFlags, FnPoint00704da0 pt);

// INFERRED: the target takes three dwords (nFlags, x, y), rebuilds the point and
// forwards it unchanged to fn_007048b0.
extern "C" void __stdcall fn_00704da0(unsigned int nFlags, int x, int y)
{
    FnPoint00704da0 pt;
    pt.x = x;
    pt.y = y;
    fn_007048b0(nFlags, pt);
}
