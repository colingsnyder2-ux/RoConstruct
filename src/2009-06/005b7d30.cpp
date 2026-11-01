// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
void g1(void* b, void* c);
void g2(void* a, void* c);
void f(void* a, void* b, void* c)
{
    g1(b, c);
    g2(a, c);
}
