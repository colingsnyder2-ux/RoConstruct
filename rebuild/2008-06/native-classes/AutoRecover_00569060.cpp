// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: fn_00568d40 is a __thiscall member (object in ecx); modelled as __fastcall
// with the object pointer first and a dummy edx argument.
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

// INFERRED: the original is a this-adjustor thunk (sub ecx,0x24; jmp 0x568d40). Under the
// required __cdecl convention the object pointer is taken from the stack and the adjusted
// pointer is forwarded to the primary-base implementation.
extern "C" int __cdecl fn_00569060(void* self)
{
    return fn_00568d40((void*)((char*)self - 0x24), 0);
}
