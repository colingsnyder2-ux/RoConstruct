// native-flags: /O2 /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: CPoint-like by-value struct (two dwords).
struct Local_00704da0_Point {
    int x;
    int y;
};

// INFERRED: callee at 007048b0 is __thiscall CXTPTabClientWnd::OnLButtonDown(UINT, CPoint);
// declaring it as a member function keeps ecx live and avoids dummy edx setup.
struct Local_00704da0_Self {
    void OnLButtonDown(unsigned int nFlags, Local_00704da0_Point pt);
};

extern "C" void __fastcall fn_00704da0(Local_00704da0_Self* self, int unusedEdx, unsigned int nFlags, Local_00704da0_Point pt)
{
    self->OnLButtonDown(nFlags, pt);
}
