// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>

struct B { int d[9]; B(const B& o); };
struct V3 { float x, y, z; V3& operator=(const V3& o) { x = o.x; y = o.y; z = o.z; return *this; } };
struct P { B b; V3 v; };
void destroy_fn(void*);
void other_fn(void*);

struct Desc {
    void (*destroy)(void*);
    void (*other)(void*);
    Desc(void (*a)(void*), void (*b)(void*)) { other = b; destroy = a; }
    virtual ~Desc();
};

struct S {
    Desc* vt;
    P storage;
    S& assign(const P& v);
};

S& S::assign(const P& v)
{
    static Desc desc(destroy_fn, other_fn);
    if (vt == &desc) {
        storage = v;
        return *this;
    }
    if (vt != 0) {
        vt->destroy(&storage);
        vt = 0;
    }
    void* p = &storage; new (p) P(v);
    vt = &desc;
    return *this;
}


