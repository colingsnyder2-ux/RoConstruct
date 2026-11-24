// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this-adjusting thunk. It subtracts 0x14 from the secondary-base
// subobject pointer and tail-jumps to func_0057bbe0, a member that takes only
// the object pointer in ecx. A single-parameter __fastcall passes that pointer
// in ecx. The return type is a guess.
extern "C" int __fastcall fn_0057bbe0(char* self);

// INFERRED: the target is declared __cdecl as the ABI check requires. The
// object pointer is taken as a plain argument.
extern "C" int __cdecl fn_0057b150(char* self)
{
    return fn_0057bbe0(self - 0x14);
}
