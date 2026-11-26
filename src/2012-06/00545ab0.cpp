// from server: 88% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void (__thiscall *F)(void*,int); struct S{char pad[0x10]; F fn; int o; int adj; int p; void f();}; void S::f(){ fn((void*)(o+adj),p); }
