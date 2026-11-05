// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cdb20 { void reg(void*); };
extern Obj_005cdb20 g_obj_005cdb20;
extern void* g_arg_005cdb20;
extern void cb_005cdb20();
extern void tail_005cdb20(void*);
extern void* __stdcall make_005cdb20(void*, int);
struct X_005cdb20 { X_005cdb20(); };
X_005cdb20::X_005cdb20() { void* p=make_005cdb20(g_arg_005cdb20,27); g_obj_005cdb20.reg(p); tail_005cdb20((void*)&cb_005cdb20); }
X_005cdb20* func_005cdb20() { static X_005cdb20 x; return &x; }
