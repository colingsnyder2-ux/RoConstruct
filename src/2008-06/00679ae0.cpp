// from server: 100% by EspClaude
// from server: 98% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <vector>

namespace Ogre {
typedef unsigned int uint32;
enum VertexElementType { VET_FLOAT1, VET_FLOAT2, VET_FLOAT3, VET_FLOAT4, VET_COLOUR };
enum VertexElementSemantic { VES_POSITION = 1, VES_BLEND_WEIGHTS, VES_BLEND_INDICES, VES_NORMAL, VES_DIFFUSE, VES_SPECULAR, VES_TEXTURE_COORDINATES };
class ColourValue {
public:
    explicit ColourValue(float red = 1.0f, float green = 1.0f, float blue = 1.0f, float alpha = 1.0f) : r(red), g(green), b(blue), a(alpha) {}
    float r, g, b, a;
};
class VertexElement {
public:
    __declspec(dllimport) static unsigned int getTypeSize(VertexElementType etype);
};
class HardwareBuffer {
public:
    virtual ~HardwareBuffer();
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void writeData(unsigned int offset, unsigned int length, const void* pSource, bool discardWholeBuffer = false) = 0;
    unsigned int getSizeInBytes() const { return mSizeInBytes; }
    unsigned int mSizeInBytes;
};
class HardwareVertexBuffer : public HardwareBuffer {};
class HardwareVertexBufferSharedPtr {
public:
    __declspec(dllimport) virtual ~HardwareVertexBufferSharedPtr();
    __declspec(dllimport) HardwareVertexBufferSharedPtr& operator=(const HardwareVertexBufferSharedPtr& r);
    HardwareVertexBuffer* operator->() const { return pRep; }
    HardwareVertexBuffer* pRep;
    unsigned int* pUseCount;
};
enum Usage { HBU_STATIC_WRITE_ONLY = 5 };
class HardwareBufferManager {
public:
    __declspec(dllimport) static HardwareBufferManager& getSingleton();
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual HardwareVertexBufferSharedPtr createVertexBuffer(unsigned int vertexSize, unsigned int numVerts, Usage usage, bool useShadowBuffer = false) = 0;
};
class VertexDeclaration {
public:
    virtual ~VertexDeclaration();
    virtual const VertexElement& addElement(unsigned short source, unsigned int offset, VertexElementType theType, VertexElementSemantic semantic, unsigned short index = 0);
};
class VertexBufferBinding {
public:
    virtual ~VertexBufferBinding();
    virtual void setBinding(unsigned short index, const HardwareVertexBufferSharedPtr& buffer);
};
class VertexData {
public:
    __declspec(dllimport) VertexData();
    VertexDeclaration* vertexDeclaration;
    VertexBufferBinding* vertexBufferBinding;
    unsigned int vertexStart;
    unsigned int vertexCount;
    char pad[0x38 - 0x10];
};
class RenderSystem {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void convertColourValue(const ColourValue& colour, uint32* pDest);
};
class Root {
public:
    __declspec(dllimport) static Root& getSingleton();
    __declspec(dllimport) RenderSystem* getRenderSystem();
};
struct Vector3 { float x, y, z; };
}

namespace RBX {
struct ColourArray : public std::vector<Ogre::uint32> { __declspec(noinline) ColourArray() {} };
struct Color4 { float r, g, b, a; };
class OgreUtil {
public:
    Ogre::VertexData* createVertexData(const Ogre::Vector3* positions, unsigned int count, const Ogre::Vector3* normals, const Color4* colors, const float* texCoords);
};

Ogre::VertexData* OgreUtil::createVertexData(const Ogre::Vector3* positions, unsigned int count, const Ogre::Vector3* normals, const Color4* colors, const float* texCoords)
{
    Ogre::RenderSystem* rs = Ogre::Root::getSingleton().getRenderSystem();
    Ogre::VertexData* vd = new Ogre::VertexData();
    vd->vertexCount = count;
    Ogre::VertexDeclaration* decl = vd->vertexDeclaration;
    unsigned short source = 0;
    decl->addElement(source, 0, Ogre::VET_FLOAT3, Ogre::VES_POSITION);
    unsigned int vsize = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
    Ogre::HardwareVertexBufferSharedPtr vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(vsize, vd->vertexCount, Ogre::HBU_STATIC_WRITE_ONLY);
    vbuf->writeData(0, vbuf->getSizeInBytes(), positions, true);
    Ogre::VertexBufferBinding* bind = vd->vertexBufferBinding;
    bind->setBinding(source, vbuf);
    ++source;
    if (colors) {
        ColourArray colourData;
        colourData.resize(count);
        for (unsigned int i = 0; i < count; ++i) {
            float ca = colors[i].r;
            float cb = colors[i].r;
            float cg = colors[i].r;
            float cr = colors[i].r;
            Ogre::ColourValue c(cr, cg, cb, ca);
            rs->convertColourValue(c, &colourData[i]);
        }
        decl->addElement(source, 0, Ogre::VET_COLOUR, Ogre::VES_DIFFUSE);
        unsigned int csize = Ogre::VertexElement::getTypeSize(Ogre::VET_COLOUR);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(csize, vd->vertexCount, Ogre::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), &colourData[0], true);
        bind->setBinding(source, vbuf);
        ++source;
    }
    if (normals) {
        decl->addElement(source, 0, Ogre::VET_FLOAT3, Ogre::VES_NORMAL);
        unsigned int size = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT3);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(size, vd->vertexCount, Ogre::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), normals, true);
        bind->setBinding(source, vbuf);
        ++source;
    }
    if (texCoords) {
        decl->addElement(source, 0, Ogre::VET_FLOAT2, Ogre::VES_TEXTURE_COORDINATES);
        unsigned int size = Ogre::VertexElement::getTypeSize(Ogre::VET_FLOAT2);
        vbuf = Ogre::HardwareBufferManager::getSingleton().createVertexBuffer(size, vd->vertexCount, Ogre::HBU_STATIC_WRITE_ONLY);
        vbuf->writeData(0, vbuf->getSizeInBytes(), texCoords, true);
        bind->setBinding(source, vbuf);
    }
    return vd;
}
}
