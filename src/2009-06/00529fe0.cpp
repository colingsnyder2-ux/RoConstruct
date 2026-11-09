// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string.h>
#include <algorithm>
struct Vector3 { float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
#pragma pack(push, 1)
struct Base {
    int a;
    Vector3 v;
    int s;
    int p;
    int q;
    bool flag;
    Base(int a_, Vector3 v_, int p_, int q_, int s_, bool f_)
        : a(a_), v(v_), s(s_), p(p_), q(q_), flag(f_) {}
    virtual size_t getData(void* dst, size_t n);
};
struct Item : Base {
    int r;
    Item(int a, Vector3 v, int p, int q, int r, int s, bool flag);
    virtual size_t getData(void* dst, size_t n);
};
#pragma pack(pop)
Item::Item(int a_, Vector3 v_, int p_, int q_, int r_, int s_, bool f_)
    : Base(a_, v_, p_, q_, s_, f_), r(r_) {}
