// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no native headers were visible, so the minimal G3D declarations
// are local, in namespace G3D, and written to give the same mangled names as
// the originals.

namespace G3D {

class Texture;

template <class T>
class ReferenceCountedPointer {
    T* m_p;
    void setPointer(T* p);
public:
    ReferenceCountedPointer() : m_p(0) {}
    ReferenceCountedPointer(T* p) : m_p(0) { setPointer(p); }
};

class Color3 {
public:
    float r, g, b;
    static const Color3& white();
};

class RenderDevice {
public:
    enum DepthTest { DEPTH_DONT_CARE, DEPTH_LEQUAL_X, DEPTH_LESS_X, DEPTH_GREATER_X };
    enum BlendFunc { BLEND_SRC_ALPHA_X, BLEND_ONE_X, BLEND_ZERO_X };
    enum BlendEq   { BLENDEQ_ADD_X, BLENDEQ_SUB_X, BLENDEQ_MAX_X };

    void pushState();
    void popState();
    void setDepthTest(DepthTest t);
    void setPolygonOffset(double offset);
    void setBlendFunc(BlendFunc src, BlendFunc dst, BlendEq eq);
    void disableLighting();
    void configureReflectionMap(unsigned int textureUnit, ReferenceCountedPointer<Texture> reflectionTexture);
    void setObjectToWorldMatrix(const class CoordinateFrame& cf);
    void setTexture(unsigned int unit, ReferenceCountedPointer<Texture> texture);
};

} // namespace G3D

extern "C" __declspec(dllimport) void __stdcall glDepthMask(unsigned char flag);
extern "C" __declspec(dllimport) void __stdcall glColor3fv(const float* v);

extern "C" unsigned char g_flag_0096ee86;  // INFERRED: global enable flag at 0x96ee86
#define g_enabled g_flag_0096ee86

extern "C" int __fastcall fn_00548fe0(void* self, int unusedEdx, int a1, int a2);

// INFERRED: object providing a texture and a brightness scale
class TexProvider {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual G3D::ReferenceCountedPointer<G3D::Texture> getTexture(G3D::RenderDevice* rd) = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual float getBrightness() = 0;
};

static const double kPolygonOffset = -1.0; // INFERRED: constant at 0x827410

template <class T>
static inline T& field(void* base, int off)
{
    return *(T*)((char*)base + off);
}

extern "C" void __fastcall fn_00502b90(void* self, int unusedEdx, G3D::RenderDevice* rd)
{
    if (!g_enabled)
        return;

    void* sub = field<void*>(self, 0x2ec);
    if (!field<void*>(sub, 0x30))
        return;

    void* tex = field<void*>(sub, 0x30);
    int dim = field<int>(tex, 0x58);
    if (dim != 5 && dim != 7)
        return;

    rd->pushState();
    rd->setDepthTest((G3D::RenderDevice::DepthTest)3);
    rd->setPolygonOffset(kPolygonOffset);
    rd->setBlendFunc((G3D::RenderDevice::BlendFunc)2,
                     (G3D::RenderDevice::BlendFunc)2,
                     (G3D::RenderDevice::BlendEq)2);
    rd->disableLighting();

    {
        G3D::ReferenceCountedPointer<G3D::Texture> refl((G3D::Texture*)field<void*>(field<void*>(self, 0x2ec), 0x30));
        rd->configureReflectionMap(1, refl);
    }

    // INFERRED: inlined RenderDevice state bookkeeping
    field<int>(rd, 0x78) += 1;
    if (field<unsigned char>(rd, 0x3e1)) {
        field<int>(rd, 0x70) += 1;
        glDepthMask(0);
        field<unsigned char>(rd, 0x3e1) = 0;
    }

    for (int i = 0; i < field<int>(self, 0x284); ++i) {
        void* item = field<void**>(self, 0x280)[i];
        TexProvider* prov = field<TexProvider*>(item, 0x34);

        rd->setPolygonOffset((double)field<float>(item, 0x38));
        rd->setObjectToWorldMatrix(*(const G3D::CoordinateFrame*)item);

        rd->setTexture(0, prov->getTexture(rd));

        float f = prov->getBrightness();
        const G3D::Color3& w = G3D::Color3::white();
        float* col = (float*)((char*)rd + 0x4a8);
        col[0] = w.r * f;
        col[1] = w.g * f;
        col[2] = w.b * f;
        col[3] = 1.0f;
        glColor3fv(col);

        void* p = field<void*>(item, 0x3c);
        fn_00548fe0(p, 0, (int)p, (int)rd);
    }

    rd->popState();
}
