// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /fp:fast /GS- /EHsc /MD
static int g;
struct S { char pad[0x1e0]; float v; void notify(const void* d); void set(float x); };
void S::set(float x) { if (x != v) { v = x; notify(&g); } }
