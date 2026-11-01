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
class Instance : public Creatable<Instance> {
public:
    static void predelete(Instance*);
protected:
    Instance();
};
class Target00605c60 : public Instance { public: Target00605c60(); char padB[0xb4 - 4]; };
template boost::shared_ptr<Target00605c60> Creatable<Instance>::create<Target00605c60>();
}
