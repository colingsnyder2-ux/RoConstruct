// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee at 0x701580 (named OnLButtonDown(UINT, CPoint) in the comments) takes
// three stack dwords and sets no ecx, so it is declared as a plain __stdcall helper.
extern "C" void __stdcall fn_00701580(unsigned int a1, int a2, int a3);

// INFERRED: the target forwards its three dword arguments unchanged.
extern "C" void __stdcall fn_007015c0(unsigned int a1, int a2, int a3)
{
    fn_00701580(a1, a2, a3);
}
