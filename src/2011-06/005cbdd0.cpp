// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbdd0 { void reg(void*); };
extern Obj_005cbdd0 g_obj_005cbdd0;
extern void* g_arg_005cbdd0;
extern void cb_005cbdd0();
extern void tail_005cbdd0(void*);
extern void* __stdcall make_005cbdd0(void*, int);
struct X_005cbdd0 { X_005cbdd0(); };
X_005cbdd0::X_005cbdd0() { void* p=make_005cbdd0(g_arg_005cbdd0,27); g_obj_005cbdd0.reg(p); tail_005cbdd0((void*)&cb_005cbdd0); }
X_005cbdd0* func_005cbdd0() { static X_005cbdd0 x; return &x; }
