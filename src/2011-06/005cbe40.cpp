// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbe40 { void reg(void*); };
extern Obj_005cbe40 g_obj_005cbe40;
extern void* g_arg_005cbe40;
extern void cb_005cbe40();
extern void tail_005cbe40(void*);
extern void* __stdcall make_005cbe40(void*, int);
struct X_005cbe40 { X_005cbe40(); };
X_005cbe40::X_005cbe40() { void* p=make_005cbe40(g_arg_005cbe40,27); g_obj_005cbe40.reg(p); tail_005cbe40((void*)&cb_005cbe40); }
X_005cbe40* func_005cbe40() { static X_005cbe40 x; return &x; }
