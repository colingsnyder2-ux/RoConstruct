// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
namespace G3D {
class Vector2 { public: float x, y; Vector2(float a, float b) : x(a), y(b) {} };
class Vector3 {
public:
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
    static const Vector3& zero() { static const Vector3 v(0, 0, 0); return v; }
};
class Rect2D {
    Vector2 min, max;
public:
    Rect2D(const Vector2& wh) : min(0, 0), max(wh.x, wh.y) {}
};
}
namespace RBX {
namespace Reflection { class ClassDescriptor; }
struct B0 { virtual void f0(); char p[0x10]; };
struct B14 { virtual void f1(); };
struct B18 { virtual void f2(); Reflection::ClassDescriptor* descriptor; };
struct B20 { virtual void f3(); char p[0x68]; };
class __declspec(novtable) IHasLocation { public: virtual void getLocation(); };
class IHasPrimaryPart { public: virtual void getPrimaryPart(); };
class PVInstance : public B0, public B14, public B18, public B20, public IHasPrimaryPart, public virtual IHasLocation { public: char pv[8]; };
class IRenderable { public: virtual void render(); char p[0xc]; };
class CameraSubject : public virtual IHasLocation { public: virtual void cameraSubject(); char p[0xc + 0x58]; };
class ModelInstance : public PVInstance, public IRenderable, public CameraSubject {
protected:
    ModelInstance();
    virtual ~ModelInstance();
};
extern long describedCount;
namespace Reflection {
template<typename Class, const char* const* ClassName, typename DerivedClass>
class __declspec(novtable) Described : public DerivedClass {
public:
    typedef Described<Class, ClassName, DerivedClass> Base;
    Described() : DerivedClass() { this->descriptor = &classDescriptor(); ++describedCount; }
    static ClassDescriptor& classDescriptor();
};
}
class Camera;
class __declspec(novtable) ICameraOwner {
public:
    ICameraOwner();
    virtual ~ICameraOwner();
    virtual Camera* getCamera() = 0;
    char p[0x18];
};
class World { public: World(); ~World(); char pad[0xbc]; };
extern const char* sRootInstance;
class RootInstance : public Reflection::Described<RootInstance, &sRootInstance, ModelInstance>, public ICameraOwner {
    mutable G3D::Vector3 insertPoint;
protected:
    G3D::Rect2D viewPort;
    std::auto_ptr<World> world;
public:
    RootInstance();
    virtual ~RootInstance();
    virtual Camera* getCamera();
    virtual void getLocation();
};
#pragma warning(disable : 4355)
RootInstance::RootInstance()
    : Base(),
      insertPoint(G3D::Vector3::zero()),
      viewPort(G3D::Vector2(800.0f, 600.0f)),
      world(new World())
{
}
}
