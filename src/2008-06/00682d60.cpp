// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_twod_add_quad_color_fork_f8f01467d94dfda6.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <list>

namespace G3D
{
    class Color4
    {
    public:
        float r;
        float g;
        float b;
        float a;
    };
}

namespace Ogre
{
    struct Quad
    {
        float x0;
        float y0;
        float x1;
        float y1;
        float u0;
        float v0;
        float u1;
        float v1;
        uint32 color;
        ResourceHandle textureHandle;
        uint32 extra0;
        uint32 extra1;
    };

    class QuadList : public RenderQueueListener
    {
    public:
        SceneManager* manager;
        bool options[3];
        void* data;
        RenderOperation operation;
        HardwareVertexBufferSharedPtr vertices;
        HardwareIndexBufferSharedPtr indices;
        std::list<Quad> quads;

        void addQuad(
            String textureName,
            const G3D::Color4& color,
            float x0, float y0, float x1, float y1,
            float u0, float v0, float u1, float v1);
    };

    typedef char QuadList_quads_offset_is_0x3c[
        offsetof(QuadList, quads) == 0x3c ? 1 : -1];

    void QuadList::addQuad(
        String textureName,
        const G3D::Color4& color,
        float x0, float y0, float x1, float y1,
        float u0, float v0, float u1, float v1)
    {
        TexturePtr texture;

        Quad quad;
        quad.x0 = x0;
        quad.y0 = y0;
        quad.x1 = x1;
        quad.y1 = y1;
        quad.u0 = u0;
        quad.v0 = v0;
        quad.u1 = u1;
        quad.v1 = v1;

        RenderSystem* renderSystem = Root::getSingleton().getRenderSystem();
        renderSystem->convertColourValue(
            ColourValue(color.r, color.g, color.b, color.a), &quad.color);
        quad.extra0 = 4;
        quad.extra1 = 0;

        if (textureName != "")
        {
            texture = TextureManager::getSingleton().getByName(textureName);
            if (texture.isNull())
                texture = TextureManager::getSingleton().load(textureName, "General");

        if (!texture.isNull())
        {
            quad.textureHandle = texture.getPointer()->getHandle();
            if ((x0 == x1) && (y0 == y1))
            {
                texture.getPointer()->getWidth();
                texture.getPointer()->getHeight();
            }
        }
        else
            quad.textureHandle = 0;
        }
        else
            quad.textureHandle = 0;

        quads.push_back(quad);
    }
}
