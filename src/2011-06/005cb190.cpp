// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb190 { void reg(void*); };
extern Obj_005cb190 g_obj_005cb190;
extern void* g_arg_005cb190;
extern void cb_005cb190();
extern void tail_005cb190(void*);
extern void* __stdcall make_005cb190(void*, int);
struct X_005cb190 { X_005cb190(); };
X_005cb190::X_005cb190() { void* p=make_005cb190(g_arg_005cb190,27); g_obj_005cb190.reg(p); tail_005cb190((void*)&cb_005cb190); }
X_005cb190* func_005cb190() { static X_005cb190 x; return &x; }
