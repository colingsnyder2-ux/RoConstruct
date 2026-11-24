// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee 0x598fa0 is ReferenceCountedPointer<Texture>::setPointer (thiscall, 1 arg, ret void).
// Target is a thiscall wrapper that forwards its arg and returns this.
struct FakeTexturePtr;

extern "C" void __fastcall fn_00598fa0(FakeTexturePtr* self, int unusedEdx, void* tex);

extern "C" FakeTexturePtr* __fastcall fn_004dc4e0(FakeTexturePtr* self, int unusedEdx, void* tex)
{
    fn_00598fa0(self, 0, tex);
    return self;
}
