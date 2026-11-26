// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
inline void* __cdecl operator new(unsigned int, void* p) throw() { return p; }

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
    float storage;
    S& assign(const float& v);
};

S& S::assign(const float& v)
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
    new (&storage) float(v);
    vt = &desc;
    return *this;
}
