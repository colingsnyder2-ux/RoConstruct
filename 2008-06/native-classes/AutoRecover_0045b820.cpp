// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Target is a single-instruction tail-jump thunk to 0x0045b2b0.
// INFERRED: callee is unnamed; thiscall-style args pass through unchanged, so
// declare it with the same fastcall layout (ecx, edx) and forward all registers.
extern "C" int __fastcall fn_0045b2b0(void* self, int unusedEdx);

extern "C" int __fastcall fn_0045b820(void* self, int unusedEdx)
{
    return fn_0045b2b0(self, unusedEdx);
}
