// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf100 { void reg(void*); };
extern Obj_005cf100 g_obj_005cf100;
extern void* g_arg_005cf100;
extern void cb_005cf100();
extern void tail_005cf100(void*);
extern void* __stdcall make_005cf100(void*, int);
struct X_005cf100 { X_005cf100(); };
X_005cf100::X_005cf100() { void* p=make_005cf100(g_arg_005cf100,27); g_obj_005cf100.reg(p); tail_005cf100((void*)&cb_005cf100); }
X_005cf100* func_005cf100() { static X_005cf100 x; return &x; }
