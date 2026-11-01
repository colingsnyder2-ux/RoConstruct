// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct ClassDescriptor;
struct B0 { virtual void f0(); char p[0x10]; };
struct B14 { virtual void f1(); };
struct B18 { virtual void f2(); const ClassDescriptor* descriptor; };
struct B20 { virtual void f3(); char p[0x68]; };
struct B8c { virtual void f4(); char p[0x1c]; };
struct Bac { virtual void f5(); char p[0x74]; };
struct B124 { virtual void f6(); };
class BodyMover : public B0, public B14, public B18, public B20, public B8c, public Bac, public B124 {
public:
    BodyMover(const char* name);
    virtual ~BodyMover();
};
template<class T> struct Described { static ClassDescriptor& classDescriptor(); };
template<class T> struct Counter { static int count; };
extern const char* sBodyVelocity;
class BodyVelocity;
template<class Class, class DerivedClass, const char* const* ClassName>
class FactoryProduct : public DerivedClass {
public:
    template<class Arg0Type> FactoryProduct(Arg0Type arg0) : DerivedClass(arg0) {}
    virtual ~FactoryProduct() {}
};
class __declspec(novtable) BodyVelocity : public FactoryProduct<BodyVelocity, BodyMover, &sBodyVelocity> {
public:
    BodyVelocity(const char* name);
};
BodyVelocity::BodyVelocity(const char* name) : FactoryProduct<BodyVelocity, BodyMover, &sBodyVelocity>(name)
{
    descriptor = &Described<BodyVelocity>::classDescriptor();
    ++Counter<BodyVelocity>::count;
}
}
