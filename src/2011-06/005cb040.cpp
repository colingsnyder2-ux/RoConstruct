// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb040 { void reg(void*); };
extern Obj_005cb040 g_obj_005cb040;
extern void* g_arg_005cb040;
extern void cb_005cb040();
extern void tail_005cb040(void*);
extern void* __stdcall make_005cb040(void*, int);
struct X_005cb040 { X_005cb040(); };
X_005cb040::X_005cb040() { void* p=make_005cb040(g_arg_005cb040,27); g_obj_005cb040.reg(p); tail_005cb040((void*)&cb_005cb040); }
X_005cb040* func_005cb040() { static X_005cb040 x; return &x; }
