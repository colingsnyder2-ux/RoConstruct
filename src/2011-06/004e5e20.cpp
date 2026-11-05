// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004e5e20 { void reg(void*); };
extern Obj_004e5e20 g_obj_004e5e20;
extern void* g_arg_004e5e20;
extern void cb_004e5e20();
extern void tail_004e5e20(void*);
extern void* __stdcall make_004e5e20(void*, int);
struct X_004e5e20 { X_004e5e20(); };
X_004e5e20::X_004e5e20() { void* p=make_004e5e20(g_arg_004e5e20,27); g_obj_004e5e20.reg(p); tail_004e5e20((void*)&cb_004e5e20); }
X_004e5e20* func_004e5e20() { static X_004e5e20 x; return &x; }
