// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd340 { void reg(void*); };
extern Obj_005cd340 g_obj_005cd340;
extern void* g_arg_005cd340;
extern void cb_005cd340();
extern void tail_005cd340(void*);
extern void* __stdcall make_005cd340(void*, int);
struct X_005cd340 { X_005cd340(); };
X_005cd340::X_005cd340() { void* p=make_005cd340(g_arg_005cd340,27); g_obj_005cd340.reg(p); tail_005cd340((void*)&cb_005cd340); }
X_005cd340* func_005cd340() { static X_005cd340 x; return &x; }
