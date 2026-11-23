// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no class header was provided, so this is a minimal local mirror of
// G3D::ReferenceCountedPointer<G3D::Texture>. Its layout is a single pointer member.
// setPointer is declared but not defined, so it links to the original symbol
// ?setPointer@?$ReferenceCountedPointer@VTexture@G3D@@@G3D@@AAEXPAVTexture@2@@Z (0x598fa0).
namespace G3D {

class Texture;

template <class T>
class ReferenceCountedPointer {
public:
    T* m_pointer;
    void setPointer(T* p);
};

typedef ReferenceCountedPointer<Texture> TexturePtr;

} // namespace G3D

// INFERRED: this is the ReferenceCountedPointer<Texture> copy constructor.
// It sets m_pointer to NULL, calls setPointer(other.m_pointer), and returns this.
extern "C" G3D::TexturePtr* __fastcall fn_005410d0(G3D::TexturePtr* self, int unusedEdx, G3D::TexturePtr* other)
{
    self->m_pointer = 0;
    self->setPointer(other->m_pointer);
    return self;
}
