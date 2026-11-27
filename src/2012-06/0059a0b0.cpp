// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char pad[0x18]; unsigned long long v; void m(unsigned a); };
void S::m(unsigned a){ v=(unsigned long long)a*1000; }
