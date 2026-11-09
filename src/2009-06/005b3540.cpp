// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct B { B(unsigned n); ~B(); unsigned& operator[](unsigned i); };
struct D : B { D(unsigned n); };
D::D(unsigned n) : B(n)
{
    for (unsigned i = 0; i < n; i++) (*this)[i] = i;
}
