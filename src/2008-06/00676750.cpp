// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-appdraw roc_unit_cbfe653928b9a501.cpp

// Candidate translation unit (score above; library headers required).
// Generated unit: RBX::AdornG3D::getTextureSize (00676750).
// The client binary proves RBX::Render::TextureProxy has a 9-slot vtable and
// dispatches resolve at byte offset 0x18 (roc vtables 2008-06):
//   [0] ~  [1..4] concrete  [5][6][7] pure  [8] new
// so resolve is a TextureProxyBase pure virtual at index 6. The vendor header
// declares it in TextureProxy at index 3, which is the only residue.
#include <string>
#include <G3D/ReferenceCount.h>
#include <G3D/Vector2.h>
#include <G3D/Rect2D.h>
#include <G3D/Color3.h>
#include <GLG3D/RenderDevice.h>
#include <GLG3D/Texture.h>
#include <GLG3D/TextureManager.h>

namespace RBX
{
    class TextureProxyBase;

    typedef G3D::ReferenceCountedPointer<TextureProxyBase> TextureProxyBaseRef;

    class TextureProxyBase : public G3D::ReferenceCountedObject
    {
    public:
        std::string filename;

        TextureProxyBase() {}
        virtual ~TextureProxyBase() {}

        virtual void  setSizeX(int v) { *(int*)((char*)this + 0x28) = v; }
        virtual int   getSizeX() { return *(int*)((char*)this + 0x28); }
        virtual void  setSizeY(float v) { *(float*)((char*)this + 0x2c) = v; }
        virtual float getSizeY() { return *(float*)((char*)this + 0x2c); }

        virtual G3D::Vector2 getSize() = 0;
        virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd) = 0;
        virtual void unusedSlot7() = 0;
    };

    namespace Render
    {
        class TextureProxy : public TextureProxyBase
        {
        public:
            virtual G3D::ReferenceCountedPointer<G3D::Texture> getIfResolved() const;
            virtual G3D::ReferenceCountedPointer<G3D::Texture> resolve(G3D::RenderDevice* rd);
            virtual G3D::Vector2 getSize();
            virtual void unusedSlot7();
            virtual ~TextureProxy();
        };
    }

    class AdornG3D
    {
    private:
        G3D::RenderDevice* renderDevice;

    public:
        virtual G3D::Rect2D getTextureSize(TextureProxyBaseRef _texture) const;
    };
}

G3D::Rect2D RBX::AdornG3D::getTextureSize(RBX::TextureProxyBaseRef _texture) const
{
    if (_texture.notNull())
    {
        RBX::Render::TextureProxy* textureProxy = static_cast<RBX::Render::TextureProxy*>(_texture.getPointer());
        G3D::TextureRef texture = textureProxy->resolve(renderDevice);

        if (texture.notNull())
            return texture->rect2DBounds();
    }

    return G3D::Rect2D();
}
