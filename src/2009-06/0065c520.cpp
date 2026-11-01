// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct V { int a; };
struct P { char pad[0x30]; V v; };
struct Q { void m(V* v); };
class C {
public:
    char pad[0x118];
    Q* q;
    void g(P* p);
    void f(P* p);
};
void C::f(P* p)
{
    q->m(&p->v);
    g(p);
}
