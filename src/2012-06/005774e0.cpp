// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
inline void* __cdecl operator new(unsigned int, void* p) throw() { return p; }

struct V3 { float x; short y; float z; short w; V3& operator=(const V3& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };
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
    V3 storage;
    S& assign(const V3& v);
};

S& S::assign(const V3& v)
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
    new (&storage) V3(v);
    vt = &desc;
    return *this;
}



