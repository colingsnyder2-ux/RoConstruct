// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* __cdecl nw(unsigned, int, int, int);
inline void* operator new(unsigned n, int a, int b, int c) { return nw(n, a, b, c); }
inline void operator delete(void*, int, int, int) {}
struct Foo { char pad[0x214]; Foo(void*); };
struct K { Foo* f(); };
Foo* K::f() { return new(0, 0, 0) Foo(this); }