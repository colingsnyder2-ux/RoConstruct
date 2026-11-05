// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cad30 { void reg(void*); };
extern Obj_005cad30 g_obj_005cad30;
extern void* g_arg_005cad30;
extern void cb_005cad30();
extern void tail_005cad30(void*);
extern void* __stdcall make_005cad30(void*, int);
struct X_005cad30 { X_005cad30(); };
X_005cad30::X_005cad30() { void* p=make_005cad30(g_arg_005cad30,27); g_obj_005cad30.reg(p); tail_005cad30((void*)&cb_005cad30); }
X_005cad30* func_005cad30() { static X_005cad30 x; return &x; }
