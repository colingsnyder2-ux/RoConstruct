// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cec30 { void reg(void*); };
extern Obj_005cec30 g_obj_005cec30;
extern void* g_arg_005cec30;
extern void cb_005cec30();
extern void tail_005cec30(void*);
extern void* __stdcall make_005cec30(void*, int);
struct X_005cec30 { X_005cec30(); };
X_005cec30::X_005cec30() { void* p=make_005cec30(g_arg_005cec30,27); g_obj_005cec30.reg(p); tail_005cec30((void*)&cb_005cec30); }
X_005cec30* func_005cec30() { static X_005cec30 x; return &x; }
