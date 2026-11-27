// from server: 88% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void imp();
void cf(void*);
void cg(int*);
struct S { int a; void* volatile p; char pad; char c; void f(); }; void S::f(){ if (p) { if (c) imp(); cf(p); } }
