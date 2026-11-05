// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P { int* px; int* pn; };
struct C {
    char pad[0x261]; bool flag;
    void h(const P& p);
    void g(const P& p);
};
void C::g(const P& p) { if (flag && p.px) h(p); }
