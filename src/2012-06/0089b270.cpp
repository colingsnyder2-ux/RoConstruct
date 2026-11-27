// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /fp:fast /GS- /EHsc /MD
static int g;
struct J { char pad[0x98]; float v; void set(float x); };
struct M { char pad[0xa8]; J* j; void notify(const void*); void set(float x); };
void M::set(float x) { if (x != j->v) { j->set(x); notify(&g); } }
