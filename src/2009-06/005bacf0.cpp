// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct D;
void h(int* p, D* a, int b);
struct D { D* first; int second; int third; D* a(); int b(); D& f(); };
D& D::f()
{
    h(&third, a()->a(), a()->b());
    return *this;
}
