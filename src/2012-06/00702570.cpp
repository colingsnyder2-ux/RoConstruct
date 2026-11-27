// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct M { char p[4]; void clear(); };
struct C { char pad[0xa1]; bool flag; char pad2[2]; M m1; M m2; M m3; void a(); void b(); void set(bool v); };
void C::set(bool v) { if (v != flag) { flag = v; if (v) { a(); } else { b(); m1.clear(); m2.clear(); m3.clear(); } } }
