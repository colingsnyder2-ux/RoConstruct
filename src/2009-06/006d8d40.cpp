// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct V { virtual void v0(); virtual int get(); };
struct S { int a; V* p; int f(V* o); };
int S::f(V* o)
{
    if (p && o && p->get() >= o->get())
        return 1;
    return 0;
}
