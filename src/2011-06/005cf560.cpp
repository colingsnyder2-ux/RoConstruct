// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf560 { void reg(void*); };
extern Obj_005cf560 g_obj_005cf560;
extern void* g_arg_005cf560;
extern void cb_005cf560();
extern void tail_005cf560(void*);
extern void* __stdcall make_005cf560(void*, int);
struct X_005cf560 { X_005cf560(); };
X_005cf560::X_005cf560() { void* p=make_005cf560(g_arg_005cf560,27); g_obj_005cf560.reg(p); tail_005cf560((void*)&cb_005cf560); }
X_005cf560* func_005cf560() { static X_005cf560 x; return &x; }
