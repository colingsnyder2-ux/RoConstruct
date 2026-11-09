// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb970 { void reg(void*); };
extern Obj_005cb970 g_obj_005cb970;
extern void* g_arg_005cb970;
extern void cb_005cb970();
extern void tail_005cb970(void*);
extern void* __stdcall make_005cb970(void*, int);
struct X_005cb970 { X_005cb970(); };
X_005cb970::X_005cb970() { void* p=make_005cb970(g_arg_005cb970,27); g_obj_005cb970.reg(p); tail_005cb970((void*)&cb_005cb970); }
X_005cb970* func_005cb970() { static X_005cb970 x; return &x; }
