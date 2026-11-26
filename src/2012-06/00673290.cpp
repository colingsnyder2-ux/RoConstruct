// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct S { char pad[0x10]; char m; void f(); };
void S::f() { char* p = &m; }