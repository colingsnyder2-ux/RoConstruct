// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the call site pushes one argument and cleans it with "add esp, 4",
// so the callee behaves as a cdecl function taking one argument. This differs
// from the 3-stack-arg __thiscall declaration given in the prompt.
extern "C" int fn_0054c640(void* a1);

extern "C" int __fastcall fn_005423f0(void* self, int unusedEdx)
{
    // INFERRED: the field at +0x18 is a pointer; its real type is unknown.
    void* field = *(void**)((char*)self + 0x18);
    return fn_0054c640(field);
}
