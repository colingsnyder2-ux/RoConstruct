// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes 9 dwords (a1,a2,a3,a4f,a5f,a6,a7,0.0f,G),
// so the callee is declared with 9 parameters rather than the 5 in the hint.
extern "C" int fn_00687860(int a1, int a2, int a3, float a4, float a5,
                           int a6, int a7, float a8, float a9);

// INFERRED: global float read from 0x84e97c
extern float g_float_0084e97c;

extern "C" int __stdcall fn_0068b5c0(int a1, int a2, int a3, float a4, float a5, int a6, int a7)
{
    return fn_00687860(a1, a2, a3, a4, a5, a6, a7, 0.0f, g_float_0084e97c);
}
