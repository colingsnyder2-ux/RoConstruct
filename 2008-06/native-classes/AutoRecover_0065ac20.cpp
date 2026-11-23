// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes only 6 dwords for fn_0067ca20 (add esp, 0x18),
// so it is declared here with 6 arguments instead of the 9 in the inferred prototype.
extern "C" int fn_0067ca20(int a1, int a2, int a3, int a4, int a5, int a6);

// INFERRED: the object type is unknown; only (this + 8) is used.
struct Unknown65ac20;

// INFERRED: the code looks like an uninitialized-fill-n style wrapper:
// arg1 = destination, arg2 = count of 8-byte elements, arg3 = value pointer.
extern "C" int __fastcall fn_0065ac20(Unknown65ac20* self, int unusedEdx, int arg1, int arg2, int arg3)
{
    // The original sets only the low byte of a stack slot to 0, then pushes the whole dword.
    union { char c; int i; } flag;
    flag.c = 0;
    fn_0067ca20(arg1, arg2, arg3, (int)((char*)self + 8), arg3, flag.i);
    return arg1 + arg2 * 8;
}
