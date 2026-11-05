// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj { int a[9]; Obj* base(); Obj* f(){ a[0]=0x8ad4c4; a[5]=0x8ad4b8; a[6]=0x8ad4b0; a[8]=0x8ad4a8; return base(); } };
Obj* func_0040aa30(Obj* x){ return x->f(); }
