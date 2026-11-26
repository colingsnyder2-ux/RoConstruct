// from server: 90% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef void (__thiscall *F)(void*,unsigned char); struct B{F fn; int o; int adj; int p; unsigned char c;}; void f(B* b){ b->fn((void*)(b->o+b->adj),b->c); }
