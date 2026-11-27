// from server: 74% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct T { virtual ~T(); int f4; void cleanup(); };
__declspec(dllimport) int __stdcall imp(void*);
static T* g;
void f() { T* p = g; if (p) { if (!imp(&p->f4)) { p->cleanup(); delete p; } g = 0; } }
