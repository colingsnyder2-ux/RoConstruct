// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc850 { void reg(void*); };
extern Obj_005cc850 g_obj_005cc850;
extern void* g_arg_005cc850;
extern void cb_005cc850();
extern void tail_005cc850(void*);
extern void* __stdcall make_005cc850(void*, int);
struct X_005cc850 { X_005cc850(); };
X_005cc850::X_005cc850() { void* p=make_005cc850(g_arg_005cc850,27); g_obj_005cc850.reg(p); tail_005cc850((void*)&cb_005cc850); }
X_005cc850* func_005cc850() { static X_005cc850 x; return &x; }
