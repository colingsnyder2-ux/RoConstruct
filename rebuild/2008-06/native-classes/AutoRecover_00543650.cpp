// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the disassembly pushes no stack arguments before the call, so the
// callee is declared with none, despite the "2 stack args" hint.
extern "C" int __fastcall fn_00550de0(void* self, int unusedEdx);

// INFERRED: the class is unknown, so the object is treated as an opaque struct.
struct Unknown543650;

extern "C" int __fastcall fn_00543650(Unknown543650* self, int unusedEdx)
{
    // INFERRED: forwards the sub-object at this+0x14 and returns the callee's eax.
    return fn_00550de0(reinterpret_cast<char*>(self) + 0x14, unusedEdx);
}
