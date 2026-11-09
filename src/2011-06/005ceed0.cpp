// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ceed0 { void reg(void*); };
extern Obj_005ceed0 g_obj_005ceed0;
extern void* g_arg_005ceed0;
extern void cb_005ceed0();
extern void tail_005ceed0(void*);
extern void* __stdcall make_005ceed0(void*, int);
struct X_005ceed0 { X_005ceed0(); };
X_005ceed0::X_005ceed0() { void* p=make_005ceed0(g_arg_005ceed0,27); g_obj_005ceed0.reg(p); tail_005ceed0((void*)&cb_005ceed0); }
X_005ceed0* func_005ceed0() { static X_005ceed0 x; return &x; }
