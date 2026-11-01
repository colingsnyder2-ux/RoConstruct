// from server: 89% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class ClassDescriptor;
class B0 { public: virtual ~B0(); int pad[4]; };
class B14 { public: virtual void f14(); };
class B18 { public: virtual void f18(); ClassDescriptor* descriptor; };
class B20 { public: virtual void f20(); };
class Instance : public B0, public B14, public B18, public B20 {
public:
    Instance();
    virtual ~Instance();
};
extern const char* const sMouse;
template<class Base, const char* const& name>
class NonFactoryProduct : public Base {
public:
    static int count;
    static ClassDescriptor& classDescriptor();
    NonFactoryProduct()
    {
        this->descriptor = &classDescriptor();
        ++count;
    }
};
template class NonFactoryProduct<Instance, sMouse>;
}
