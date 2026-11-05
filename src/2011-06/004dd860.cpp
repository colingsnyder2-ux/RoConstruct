// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004dd860 { void reg(void*); };
extern Obj_004dd860 g_obj_004dd860;
extern void* g_arg_004dd860;
extern void cb_004dd860();
extern void tail_004dd860(void*);
extern void* __stdcall make_004dd860(void*, int);
struct X_004dd860 { X_004dd860(); };
X_004dd860::X_004dd860() { void* p=make_004dd860(g_arg_004dd860,27); g_obj_004dd860.reg(p); tail_004dd860((void*)&cb_004dd860); }
X_004dd860* func_004dd860() { static X_004dd860 x; return &x; }
