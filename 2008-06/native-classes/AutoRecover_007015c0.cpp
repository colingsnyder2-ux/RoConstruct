// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: CPoint-like by-value struct (two dwords).
struct Local_007015c0_Point {
    int x;
    int y;
};

// INFERRED: callee at 00701580 is __thiscall CXTPTabClientWnd::CSingleWorkspace::OnLButtonDown(UINT, CPoint);
// declaring it as a member function keeps ecx live and avoids dummy edx setup.
struct Local_007015c0_Self {
    void OnLButtonDown(unsigned int nFlags, Local_007015c0_Point pt);
};

extern "C" void __fastcall fn_007015c0(Local_007015c0_Self* self, int unusedEdx, unsigned int nFlags, Local_007015c0_Point pt)
{
    self->OnLButtonDown(nFlags, pt);
}
