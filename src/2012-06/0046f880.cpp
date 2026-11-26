// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <new>
__declspec(dllimport) void* __cdecl Alloc(size_t);
struct X { virtual void f(); };
X* make() { void* p = Alloc(4); return p ? new (p) X : 0; }