// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int size_t;
extern "C" void* __cdecl malloc(size_t);
extern "C" void __cdecl free(void*);
namespace boost {
namespace detail { class shared_count { public: void* pi_; ~shared_count(); }; }
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    template<class Y, class D> shared_ptr(Y* p, D d);
};
}
namespace RBX {
class Object { public: virtual ~Object() {} };
template<class T> class Creatable : public Object {
public:
    class Deleter { public: void operator()(T* instance) { T::predelete(instance); delete instance; } };
    template<class U> static boost::shared_ptr<U> create() { return boost::shared_ptr<U>(new U(), Deleter()); }
protected:
    Creatable() {}
    virtual ~Creatable() {}
    static void* operator new(size_t size) { return malloc(size); }
    static void operator delete(void* p) { free(p); }
};
struct P1 { virtual void f1(); };
struct P2 { virtual void f2(); int x; };
struct P3 { virtual void f3(); char pad[0x68]; };
struct P4 { virtual void f4(); };
class Instance;
class ExeHead : public Creatable<Instance> { protected: ExeHead() {} char padH[0x10]; };
class Instance : public ExeHead, public P1, public P2, public P3, public P4 {
public:
    static void predelete(Instance*);
protected:
    Instance();
};
class Base004c16f0 : public Instance { protected: Base004c16f0(); char padB[0xd0 - 0x90]; };
class Target004c16f0 : public Base004c16f0 { public: Target004c16f0() {} };
template boost::shared_ptr<Target004c16f0> Creatable<Instance>::create<Target004c16f0>();
}
