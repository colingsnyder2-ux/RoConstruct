// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available, so the compiler-generated adjustor
// thunk cannot be produced from the real class. It is emulated by a __fastcall
// forwarder that adjusts ecx by -0xC4 and tail-jumps (same stack args, edx
// passed through untouched) to the real vector deleting destructor at 0x005b6e20.
extern "C" void* __fastcall fn_005b6e20(void* self, int unusedEdx, unsigned int flags);

extern "C" void* __fastcall FactoryProduct_SoundChannel_vdtor_adjustor196(char* self, int edx, unsigned int flags)
{
    return fn_005b6e20(self - 0xC4, edx, flags);
}
