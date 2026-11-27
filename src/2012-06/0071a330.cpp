// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct S { int a[4]; };
S gDefault;
struct M { char pad[0x94]; int flag; char p2[0x28]; S s; const S& f() const; };

const S& M::f() const { if (!flag) return s; return gDefault; }
