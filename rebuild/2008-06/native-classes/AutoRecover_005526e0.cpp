// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so the types are minimal local stand-ins.
// The target returns a G3D::ReferenceCountedPointer<Texture> by value. The single
// stack argument is the hidden return slot, and the function returns that pointer in eax.
namespace G3D {
    class Texture;
    template <class T>
    class ReferenceCountedPointer {
    public:
        T* m_pointer;
        void* m_rc;
    };
}

struct TextureHolder; // INFERRED: owner class, holds the texture pointer at +0x28

typedef G3D::ReferenceCountedPointer<G3D::Texture> TexturePtr;

// ??0?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@QAE@ABV01@@Z (copy constructor)
extern "C" TexturePtr* __fastcall fn_004f0820(TexturePtr* self, int unusedEdx, const TexturePtr* other);

extern "C" TexturePtr* __fastcall fn_005526e0(TextureHolder* self, int unusedEdx, TexturePtr* out)
{
    fn_004f0820(out, 0, reinterpret_cast<const TexturePtr*>(reinterpret_cast<char*>(self) + 0x28));
    return out;
}
