// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbcf0 { void reg(void*); };
extern Obj_005cbcf0 g_obj_005cbcf0;
extern void* g_arg_005cbcf0;
extern void cb_005cbcf0();
extern void tail_005cbcf0(void*);
extern void* __stdcall make_005cbcf0(void*, int);
struct X_005cbcf0 { X_005cbcf0(); };
X_005cbcf0::X_005cbcf0() { void* p=make_005cbcf0(g_arg_005cbcf0,27); g_obj_005cbcf0.reg(p); tail_005cbcf0((void*)&cb_005cbcf0); }
X_005cbcf0* func_005cbcf0() { static X_005cbcf0 x; return &x; }
