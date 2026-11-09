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
struct Deleter { void operator()(void*) const; };
class Obj { public: Obj(int, int, int, int, int); char pad[0x2f20]; };
boost::shared_ptr<Obj> createObj(int a, int b, int c, int d, int e) {
    return boost::shared_ptr<Obj>(new Obj(a, b, c, d, e), Deleter());
}
}
