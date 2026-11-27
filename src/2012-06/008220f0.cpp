// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
static int g[4];
struct S { char pad[0xb4]; float v; void notify(void*); void set(float x); };
void S::set(float x) { v = x; notify(&g); }
