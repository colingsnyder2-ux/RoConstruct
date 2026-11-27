// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Q{ void g(int*); }; struct S{ char pad[0xc]; Q q; void m(int a); };
void S::m(int a){ char t[0x18]; q.g(&a); }

