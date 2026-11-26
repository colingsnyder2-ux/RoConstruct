// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <map>
struct Base {
    Base(const void* a, const void* b);
    virtual ~Base();
    char pad[0x30];
};
struct X {
    int a, b, c, d;
    X() : a(0), b(0), c(0) {}
    ~X();
};
struct Derived : Base {
    std::map<int, int> m1;
    std::map<int, int> m2;
    int pad4c;
    X x1, x2, x3, x4, x5, x6;
    Derived();
    void add(int idx, const char* name);
};
extern char g_desc, g_vt;
extern const char g_n0[], g_n1[], g_n2[];
Derived::Derived() : Base(&g_desc, &g_vt)
{
    add(0, g_n0);
    add(1, g_n1);
    add(2, g_n2);
}
