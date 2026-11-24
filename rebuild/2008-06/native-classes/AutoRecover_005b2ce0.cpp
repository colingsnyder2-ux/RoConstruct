// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header is available for RBX::Hat / DescribedCreatable, so the
// vtordisp{-4,464} vector-deleting-destructor thunk is written as a plain function.
// It adjusts `this` by the vtordisp value stored at this-4 and then by 0x1d0,
// and forwards to the real vector deleting destructor at 0x005b2ea0.
// INFERRED: the checker reports the original as __cdecl, so the adjusted object
// pointer is passed explicitly as the first argument.

extern "C" void* __fastcall fn_005b2ea0(void* self, int unusedEdx, unsigned int flags);

extern "C" void* __cdecl fn_005b2ce0(char* self, unsigned int flags)
{
    int vtordisp = *reinterpret_cast<int*>(self - 4);
    return fn_005b2ea0(self - vtordisp - 0x1d0, 0, flags);
}
