// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cae80 { void reg(void*); };
extern Obj_005cae80 g_obj_005cae80;
extern void* g_arg_005cae80;
extern void cb_005cae80();
extern void tail_005cae80(void*);
extern void* __stdcall make_005cae80(void*, int);
struct X_005cae80 { X_005cae80(); };
X_005cae80::X_005cae80() { void* p=make_005cae80(g_arg_005cae80,27); g_obj_005cae80.reg(p); tail_005cae80((void*)&cb_005cae80); }
X_005cae80* func_005cae80() { static X_005cae80 x; return &x; }
