// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct B0 { virtual void f0(); char p[0x10]; };
struct B14 { virtual void f1(); };
struct B18 { virtual void f2(); void* descriptor; };
struct B20 { virtual void f3(); char p[0x68]; };
class __declspec(novtable) IHasLocation { public: virtual void getLocation(); };
class IHasPrimaryPart { public: virtual void getPrimaryPart(); };
class PVInstance : public B0, public B14, public B18, public B20, public IHasPrimaryPart, public virtual IHasLocation { public: char pv[8]; };
class IRenderable { public: virtual void render(); char p[0xc]; };
class CameraSubject : public virtual IHasLocation { public: virtual void cameraSubject(); char p[0xc + 0x58]; };
struct PadC0 { char p[0x58]; };
class ICameraOwner { public: virtual void getCamera(); };
class RootInstance : public PVInstance, public IRenderable, public CameraSubject, public ICameraOwner {
public:
    char pad[0x154 - 0x11c];
    RootInstance();
    virtual ~RootInstance();
    virtual void getLocation();
};
extern const char* sWorkspace;
template<class DerivedClass, const char* const* ClassName>
class NonFactoryProduct : public DerivedClass {
public:
    NonFactoryProduct() : DerivedClass() {}
    virtual ~NonFactoryProduct();
};
template NonFactoryProduct<RootInstance, &sWorkspace>::NonFactoryProduct();
}
