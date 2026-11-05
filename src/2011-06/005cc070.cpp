// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc070 { void reg(void*); };
extern Obj_005cc070 g_obj_005cc070;
extern void* g_arg_005cc070;
extern void cb_005cc070();
extern void tail_005cc070(void*);
extern void* __stdcall make_005cc070(void*, int);
struct X_005cc070 { X_005cc070(); };
X_005cc070::X_005cc070() { void* p=make_005cc070(g_arg_005cc070,27); g_obj_005cc070.reg(p); tail_005cc070((void*)&cb_005cc070); }
X_005cc070* func_005cc070() { static X_005cc070 x; return &x; }
