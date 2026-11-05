// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb120 { void reg(void*); };
extern Obj_005cb120 g_obj_005cb120;
extern void* g_arg_005cb120;
extern void cb_005cb120();
extern void tail_005cb120(void*);
extern void* __stdcall make_005cb120(void*, int);
struct X_005cb120 { X_005cb120(); };
X_005cb120::X_005cb120() { void* p=make_005cb120(g_arg_005cb120,27); g_obj_005cb120.reg(p); tail_005cb120((void*)&cb_005cb120); }
X_005cb120* func_005cb120() { static X_005cb120 x; return &x; }
