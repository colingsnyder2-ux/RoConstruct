// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object with two heap pointers at +4 and +8; +4 holds an Ogre
// object with a TexturePtr member at +0x20c. Layout from disassembly only.
struct Obj670710 {
    int pad0;
    char* owned;     // +4, object with TexturePtr at +0x20c
    void* buffer;    // +8
};

// TexturePtr destructor, imported from rgmain (thiscall, ecx = this)
extern "C" void __fastcall fn_00804c8c_TexturePtrDtor(void* self, int unusedEdx);

extern "C" void __fastcall fn_00670710(Obj670710* self, int unusedEdx)
{
    char* p = self->owned;
    if (p) {
        fn_00804c8c_TexturePtrDtor(p + 0x20c, 0);
        operator delete(p);
    }
    operator delete(self->buffer);
}
