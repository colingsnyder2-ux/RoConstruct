// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf410 { void reg(void*); };
extern Obj_005cf410 g_obj_005cf410;
extern void* g_arg_005cf410;
extern void cb_005cf410();
extern void tail_005cf410(void*);
extern void* __stdcall make_005cf410(void*, int);
struct X_005cf410 { X_005cf410(); };
X_005cf410::X_005cf410() { void* p=make_005cf410(g_arg_005cf410,27); g_obj_005cf410.reg(p); tail_005cf410((void*)&cb_005cf410); }
X_005cf410* func_005cf410() { static X_005cf410 x; return &x; }
