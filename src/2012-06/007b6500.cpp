// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base { char pad[0x84]; Base(int); };
struct V { int v; };
struct D : Base, virtual V { int m88; int m8c; D(int a); };
D::D(int a) : Base(a) { m8c = 0; }
