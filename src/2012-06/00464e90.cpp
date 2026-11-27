// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
struct VT { int pad; void (__cdecl* fn)(void*); };
struct S { char p[0xc]; VT* vt; char buf[8]; void f(); };
void S::f() { if (vt) vt->fn(buf); }
