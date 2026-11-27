// from server: 98% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj { char d[36]; Obj(const Obj&); ~Obj(); };
struct S { int a; Obj o; S(const S& s) : a(s.a), o(s.o) {} };
struct G { char x; bool m(S s, void* p); };
extern G g;
struct C { void* p; int pad; char member[4]; C(S s); };
C::C(S s) { p = g.m(s, member) ? &g : 0; }

