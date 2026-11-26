// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <new>
// roc-flags: /O2 /GS- /EHsc /MD


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
    char storage[sizeof(std::string)];
    S(const std::string& v);
};

S::S(const std::string& v)
{
    vt = 0;
    void* p = &storage; new (p) std::string(v);
    static Desc desc(destroy_fn, other_fn);
    vt = &desc;
}



