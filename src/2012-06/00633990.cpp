// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
void __cdecl xfree(void*);
struct S { virtual void v(); int x; void* p; ~S(); };
S::~S() { xfree(p); p = 0; }
void S::v() {}
