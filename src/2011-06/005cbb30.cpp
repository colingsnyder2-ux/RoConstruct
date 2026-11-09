// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbb30 { void reg(void*); };
extern Obj_005cbb30 g_obj_005cbb30;
extern void* g_arg_005cbb30;
extern void cb_005cbb30();
extern void tail_005cbb30(void*);
extern void* __stdcall make_005cbb30(void*, int);
struct X_005cbb30 { X_005cbb30(); };
X_005cbb30::X_005cbb30() { void* p=make_005cbb30(g_arg_005cbb30,27); g_obj_005cbb30.reg(p); tail_005cbb30((void*)&cb_005cbb30); }
X_005cbb30* func_005cbb30() { static X_005cbb30 x; return &x; }
