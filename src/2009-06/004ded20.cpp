// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Inner { bool h(void* c, void* b); };
template<class T> struct sp { T* px; void* pn; T* operator->() const { return px; } };
struct S {
    char pad[0x2ab0];
    sp<Inner> inner;
    void g(void* a, void* c);
    bool f(void* a, void* b, void* c);
};
bool S::f(void* a, void* b, void* c)
{
    g(a, c);
    return inner->h(c, b);
}
