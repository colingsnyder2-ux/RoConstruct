// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc310 { void reg(void*); };
extern Obj_005cc310 g_obj_005cc310;
extern void* g_arg_005cc310;
extern void cb_005cc310();
extern void tail_005cc310(void*);
extern void* __stdcall make_005cc310(void*, int);
struct X_005cc310 { X_005cc310(); };
X_005cc310::X_005cc310() { void* p=make_005cc310(g_arg_005cc310,27); g_obj_005cc310.reg(p); tail_005cc310((void*)&cb_005cc310); }
X_005cc310* func_005cc310() { static X_005cc310 x; return &x; }
