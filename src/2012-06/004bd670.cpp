// from server: 99% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Sub { char d[0x24]; Sub(const Sub&); ~Sub(); };
struct P { int a; Sub s; };
struct G { bool test(P p, void* m); };
G gg;
struct X { void* g; char pad[4]; char m8[8]; void set(P p); };
void X::set(P p) { g = gg.test(p, m8) ? &gg : 0; }
