// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ccc40 { void reg(void*); };
extern Obj_005ccc40 g_obj_005ccc40;
extern void* g_arg_005ccc40;
extern void cb_005ccc40();
extern void tail_005ccc40(void*);
extern void* __stdcall make_005ccc40(void*, int);
struct X_005ccc40 { X_005ccc40(); };
X_005ccc40::X_005ccc40() { void* p=make_005ccc40(g_arg_005ccc40,27); g_obj_005ccc40.reg(p); tail_005ccc40((void*)&cb_005ccc40); }
X_005ccc40* func_005ccc40() { static X_005ccc40 x; return &x; }
