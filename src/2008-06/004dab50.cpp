// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <string>

namespace Ogre {
struct Quaternion { float w, x, y, z; static __declspec(dllimport) const Quaternion IDENTITY; };
struct ResourceGroupManager { static __declspec(dllimport) std::string DEFAULT_RESOURCE_GROUP_NAME; };
struct Vector3 { float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; } };
struct ColourValue { float r, g, b, a; ColourValue() {} ColourValue(float x, float y, float z, float w) : r(x), g(y), b(z), a(w) {}
    ColourValue& operator=(const ColourValue& c) { r = c.r; g = c.g; b = c.b; a = c.a; return *this; } };
class Exception {
public:
    virtual ~Exception();
    long line;
    int number;
    std::string typeName;
    std::string description;
    const std::string& getDescription() const { return description; }
};
}

namespace G3D {
struct Vector3 { float x, y, z; };
struct Color3 { float r, g, b; Color3() {} Color3(const Color3& o) : r(o.r), g(o.g), b(o.b) {} };
struct Color4 { float r, g, b, a; };
class LightingParameters {
public:
    char data[0xf8];
    LightingParameters(const LightingParameters&);
    ~LightingParameters();
};
}

inline Ogre::Vector3 toOgre(const G3D::Vector3& v) { return Ogre::Vector3(v.x, v.y, v.z); }
inline Ogre::ColourValue toOgre(const G3D::Color4& c) { return Ogre::ColourValue(c.r, c.g, c.b, c.a); }

namespace RBX {
class StandardOut {
public:
    void printf(int type, const char* format, ...);
};
struct OutPtr {
    StandardOut* px;
    void* pn;
    ~OutPtr();
    StandardOut* operator->() const { return px; }
};
OutPtr singletonStandardOut();

class Lighting {
public:
    char pad[0x130];
    G3D::LightingParameters params;      // 0x130
    G3D::Color3 ambientTop;              // 0x228
    G3D::Color3 ambientBottom;           // 0x234
    bool hasSky;                         // 0x240
    G3D::Color4 colour1;                 // 0x244
    G3D::Color4 colour2;                 // 0x254
    char pad264[0xc];
    G3D::Vector3 v0;                     // 0x270
    G3D::Vector3 v1;                     // 0x27c
    float f0;                            // 0x288
    G3D::Vector3 v2;                     // 0x28c
    G3D::Vector3 v3;
    G3D::Vector3 v4;
    G3D::Vector3 v5;
    G3D::Vector3 v6;
    G3D::Vector3 v7;
};

struct LightingHandle { Lighting* get(); };

struct SkyRef { void* p; SkyRef(void* x) : p(x) {} };
namespace RenderBase {
class RenderSceneBase {
public:
    virtual ~RenderSceneBase();
    virtual void setLighting(SkyRef, G3D::LightingParameters, G3D::Color3, G3D::Color3);
};
}
namespace RenderNew {
class RenderScene : public RenderBase::RenderSceneBase {
public:
    char pad4[0x10];
    Ogre::ColourValue colour1;           // 0x14
    char pad24[0x328 - 0x24];
    Ogre::ColourValue colour2;           // 0x328
    Ogre::Vector3 v0;                    // 0x338
    Ogre::Vector3 v1;
    float f0;                            // 0x350
    Ogre::Vector3 v2;
    Ogre::Vector3 v3;
    Ogre::Vector3 v4;
    Ogre::Vector3 v5;
    Ogre::Vector3 v6;
    Ogre::Vector3 v7;
};
}

struct Context;
struct LightingListener { void onLighting(Context*, const G3D::LightingParameters*); };

class SceneManager {
public:
#define V(n) virtual void v##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101)
#undef V
    virtual void setSkyBox(bool enable, const std::string& materialName, float distance = 5000,
        bool drawFirst = true, const Ogre::Quaternion& orientation = Ogre::Quaternion::IDENTITY,
        const std::string& groupName = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
    char pad[0x8bdc - 4];
    struct ListenerPtr { LightingListener* px; typedef LightingListener* ListenerPtr::*ub; operator ub() const { return px == 0 ? 0 : &ListenerPtr::px; } LightingListener* operator->() const { return px; } void* pn; } listener;
};

struct Context {
    void* reserved;
    SceneManager* sceneManager;
};

namespace ViewNew {
class ViewRbxGfx {
public:
    char pad0[8];
    RenderBase::RenderSceneBase* scene;  // 0x8
    char pad0c[8];
    LightingHandle* lighting;            // 0x14
    char pad18[0x2c];
    bool updated;                        // 0x44
    char pad45[3];
    bool skyInitialized;                 // 0x48
    void initSky(Context*);
    void updateLighting(Context*);
};

void ViewRbxGfx::updateLighting(Context* context)
{
    if (updated)
        return;
    Lighting* l = lighting ? lighting->get() : 0;
    if (!l->hasSky) {
        context->sceneManager->setSkyBox(false, "");
    } else if (!skyInitialized) {
        try {
            initSky(context);
            skyInitialized = true;
        } catch (Ogre::Exception& e) {
            singletonStandardOut()->printf(3, "Failed to load sky box. %s", e.getDescription().c_str());
        } catch (...) {
            singletonStandardOut()->printf(3, "Failed to load sky box");
        }
    }
    RenderBase::RenderSceneBase* s = scene;
    s->setLighting(0, l->params, l->ambientTop, l->ambientBottom);
    RenderNew::RenderScene* rs = dynamic_cast<RenderNew::RenderScene*>(scene);
    rs->colour1 = toOgre(l->colour1);
    rs->colour2 = toOgre(l->colour2);
    rs->v0 = toOgre(l->v0);
    rs->v1 = toOgre(l->v1);
    rs->f0 = l->f0;
    rs->v2 = toOgre(l->v2);
    rs->v3 = toOgre(l->v3);
    rs->v4 = toOgre(l->v4);
    rs->v5 = toOgre(l->v5);
    rs->v6 = toOgre(l->v6);
    rs->v7 = toOgre(l->v7);
    if (context->sceneManager->listener)
        context->sceneManager->listener->onLighting(context, &l->params);
    updated = true;
}
}
}
