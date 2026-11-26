// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct B{ __declspec(dllimport) void m(const char*); };
extern const char s[];
struct S{ char p[0xb04]; B b; void f(); };
void S::f(){ b.m(s); }
