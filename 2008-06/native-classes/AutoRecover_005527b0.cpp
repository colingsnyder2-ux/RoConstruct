// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: wrapper calling G3D::Array<const void*>::resize(0) (clear without dealloc); ABI from disassembly.
extern "C" void __fastcall fn_00503100(void* self, int unusedEdx, int newSize);
extern "C" void __fastcall fn_005527b0(void* self, int unusedEdx);

extern "C" void __fastcall fn_005527b0(void* self, int unusedEdx)
{
    fn_00503100(self, 0, 0);
}
