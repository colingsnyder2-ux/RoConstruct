// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
struct B { char pad[0x60]; B(int,int,int); virtual void v(); };
struct D : B { float x, y, z; D(int a, int b, int c); virtual void v(); };
D::D(int a, int b, int c) : B(a, b, c) { x = 0.0f; y = 0.0f; z = 0.0f; }
