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
template<class R, class F, class L> class bind_t { public: F f_; L l_; bind_t(F f, L l) : f_(f), l_(l) {} };
template<class Sig> class function {
public:
    void* vtable;
    char storage[0x1c];
    template<class F> function(F f) : vtable(0) { assign_to(f); }
    template<class F> void assign_to(F f) throw();
};
}
namespace RBX {
class Object { public: virtual ~Object() {} };
template<class T> class Creatable : public Object {
public:
    class Deleter { public: void operator()(T* instance) { T::predelete(instance); delete instance; } };
    template<class U, class A1> static boost::shared_ptr<U> create(A1 a1) { return boost::shared_ptr<U>(new U(a1), Deleter()); }
protected:
    Creatable() {}
    virtual ~Creatable() {}
    static void* operator new(size_t size) { return malloc(size); }
    static void operator delete(void* p) { free(p); }
};
struct P1 { virtual void f1(); };
struct P2 { virtual void f2(); int x; };
struct P3 { virtual void f3(); char pad[0x68]; };
class Instance;
class ExeHead : public Creatable<Instance> { protected: ExeHead() {} char padH[0x10]; };
class Instance : public ExeHead, public P1, public P2, public P3 {
public:
    static void predelete(Instance*);
protected:
    Instance();
};
class BaseB : public Instance { protected: BaseB(); char padB[0xb8 - 0x8c]; };
int identityB(int x);
class TargetB : public BaseB {
public:
    boost::function<int(int)> fn;
    __forceinline TargetB(int a) : fn(boost::bind_t<int, int(*)(int), int>(&identityB, a)) {}
};
template boost::shared_ptr<TargetB> Creatable<Instance>::create<TargetB, int>(int);
}
