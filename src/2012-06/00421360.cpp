// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned char g;
extern void __cdecl lg(int, const char*, int);
struct X { void next(); void f(); };
void X::f() { if (g) lg(g, "DSVideoCaptureEngine: Device lost", 0); next(); }