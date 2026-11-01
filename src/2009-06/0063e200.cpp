// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class ClassDescriptor { public: int x; }; }
struct __declspec(novtable) VB { virtual void vbf(); int x; };
struct B0 { virtual ~B0(); char p[0x10]; };
struct B14 { virtual void b14(); };
struct B18 { virtual void b18(); const Reflection::ClassDescriptor* descriptor; };
struct B20 { virtual void b20(); char p[0x68]; };
struct B8c { virtual void b8c(); char p[0xc]; };
struct B9c { virtual void b9c(); char p[0xc]; };
struct Bac : public virtual VB { virtual void bac(); };
class Accoutrement : public B0, public B14, public B18, public B20, public B8c, public B9c, public Bac {
public:
    Accoutrement();
    ~Accoutrement();
    virtual void vbf();
    char m[0x58];
};
extern const char* const sHat;
template<class Class, class DerivedClass, const char* const* ClassName>
class FactoryProduct : public DerivedClass {
public:
    FactoryProduct();
    ~FactoryProduct();
};
namespace Reflection {
template<class T> struct ExeCounter { static int n; };
template<typename Class, const char* const* ClassName, typename DerivedClass>
class __declspec(novtable) Described : public DerivedClass {
public:
    Described() : DerivedClass()
    {
        this->descriptor = &classDescriptor();
        ++ExeCounter<Class>::n;
    }
    static ClassDescriptor& classDescriptor();
};
}
template<typename Class, typename DerivedClass, const char* const* ClassName>
class DescribedCreatable : public Reflection::Described<Class, ClassName, FactoryProduct<Class, DerivedClass, ClassName> > {
public:
    DescribedCreatable();
};
template<typename Class, typename DerivedClass, const char* const* ClassName>
DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}
class Hat;
template class DescribedCreatable<Hat, Accoutrement, &sHat>;
}
