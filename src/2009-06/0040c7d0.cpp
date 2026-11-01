// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
    T* px; void* pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace RBX {
class GuidItemBase { public: virtual ~GuidItemBase(); int g[4]; };
class AbstractFactoryProductBase { public: virtual ~AbstractFactoryProductBase(); };
class DescribedBase { public: virtual ~DescribedBase(); int descriptor; };
class Debugable { public: virtual ~Debugable(); int d; };
class Base : public GuidItemBase, public AbstractFactoryProductBase, public DescribedBase, public Debugable {
public:
    Base();
    virtual ~Base();
    char pad[0xac - 0x28];
};
class Obj : public Base {
public:
    int a; int b;
    Obj() : a(-1), b(0) {}
};
struct Deleter { void operator()(void*) const; };
template<class B> class Creatable { public: template<class T> static boost::shared_ptr<T> create() { return boost::shared_ptr<T>(new T(), Deleter()); } };
template boost::shared_ptr<Obj> Creatable<Base>::create<Obj>();
}
