// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was available. The layout is a guess from the disassembly:
// two bytes, a float at +4, and a G3D::ReferenceCountedPointer<Texture> at +8.
struct TexturePtrOpaque {
    void* ptr;
};

struct TextureSlot {
    char  b0;
    char  b1;
    float f;
    TexturePtrOpaque tex;
};

// ??0?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@QAE@ABV01@@Z
extern "C" void __fastcall fn_004f0820(TexturePtrOpaque* self, int unusedEdx, const TexturePtrOpaque* other);

// INFERRED: this is a copy constructor of an unnamed class, so it takes the
// source object by pointer and returns the destination.
extern "C" TextureSlot* __fastcall fn_005429e0(TextureSlot* self, int unusedEdx, const TextureSlot* other)
{
    self->b0 = other->b0;
    self->b1 = other->b1;
    self->f  = other->f;
    fn_004f0820(&self->tex, 0, &other->tex);
    return self;
}
