// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the original is a thiscall thunk (ecx = this) that adds 8 to `this`
// and tail-calls fn_0049f710. The harness requires a __cdecl definition, so `self`
// is passed as an ordinary stack argument. The callee's return type and any stack
// arguments are unknown.
extern "C" int __fastcall fn_0049f710(void* self);

extern "C" int __fastcall fn_005965c0(void* self)
{
    return fn_0049f710(static_cast<char*>(self) + 8);
}
