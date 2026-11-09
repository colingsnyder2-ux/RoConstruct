// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cde30 { void reg(void*); };
extern Obj_005cde30 g_obj_005cde30;
extern void* g_arg_005cde30;
extern void cb_005cde30();
extern void tail_005cde30(void*);
extern void* __stdcall make_005cde30(void*, int);
struct X_005cde30 { X_005cde30(); };
X_005cde30::X_005cde30() { void* p=make_005cde30(g_arg_005cde30,27); g_obj_005cde30.reg(p); tail_005cde30((void*)&cb_005cde30); }
X_005cde30* func_005cde30() { static X_005cde30 x; return &x; }
