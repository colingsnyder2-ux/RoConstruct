// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall fn(void*, const void*);
extern char g;
struct S { char p[0x35]; bool b; void f(void* a); };
void S::f(void* a) { b = fn(a, &g) != 0; }