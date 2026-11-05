// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0058fdd0 { void reg(void*); };
extern Obj_0058fdd0 g_obj_0058fdd0;
extern void* g_arg_0058fdd0;
extern void cb_0058fdd0();
extern void tail_0058fdd0(void*);
extern void* __stdcall make_0058fdd0(void*, int);
struct X_0058fdd0 { X_0058fdd0(); };
X_0058fdd0::X_0058fdd0() { void* p=make_0058fdd0(g_arg_0058fdd0,27); g_obj_0058fdd0.reg(p); tail_0058fdd0((void*)&cb_0058fdd0); }
X_0058fdd0* func_0058fdd0() { static X_0058fdd0 x; return &x; }
