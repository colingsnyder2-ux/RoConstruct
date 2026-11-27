// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct CS { int d[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCS(CS*);
extern "C" __declspec(dllimport) void __stdcall LeaveCS(CS*);
struct Guard { CS* p; Guard(CS* c) : p(c) { EnterCS(c); } ~Guard() { LeaveCS(p); } };
struct T { int a, b, c; };
struct Sub { void go(T* out, int* in); };
struct X { int pad0; CS cs; char pad[0x1c0 - 4 - sizeof(CS)]; Sub sub; void f(int a); };
void X::f(int a) { Guard g(&cs); T t; sub.go(&t, &a); }