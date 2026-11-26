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

#pragma pack(push,4)
struct S {
    Desc* vt;
    double storage;
    S& assign(const double& v);
};
#pragma pack(pop)

S& S::assign(const double& v)
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
    new (&storage) double(v);
    vt = &desc;
    return *this;
}


