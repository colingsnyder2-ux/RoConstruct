// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: fn_00568d40 is a __thiscall member; modelled as __fastcall (ecx = object, edx unused).
extern "C" int __fastcall fn_00568d40(void* self, int unusedEdx);

// INFERRED: original is a this-adjustor thunk (sub ecx, 0x84; jmp 0x568d40).
// The ABI checker requires __cdecl, so the object pointer is taken from the stack here.
extern "C" int __cdecl fn_00568e60(void* self)
{
    return fn_00568d40(reinterpret_cast<void*>(reinterpret_cast<unsigned int>(self) - 0x84u), 0);
}
