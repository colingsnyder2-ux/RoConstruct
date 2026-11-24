// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a this-adjusting thunk (secondary base subobject at +0x10 -> primary object)
// that tail-jumps to the real implementation at 0x0057bbe0 (sub ecx,0x10 / jmp).
// The callee receives the adjusted object pointer in ecx (thiscall modelled as __fastcall).
extern "C" int __fastcall fn_0057bbe0(void* self, int unusedEdx);

// INFERRED: declared __cdecl per the ABI requirement (plain ret, caller pops); the object
// pointer is modelled as the single argument.
extern "C" int __cdecl fn_0057b140(char* self)
{
    return fn_0057bbe0(self - 0x10, 0);
}
