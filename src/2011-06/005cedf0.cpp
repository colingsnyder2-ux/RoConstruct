// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cedf0 { void reg(void*); };
extern Obj_005cedf0 g_obj_005cedf0;
extern void* g_arg_005cedf0;
extern void cb_005cedf0();
extern void tail_005cedf0(void*);
extern void* __stdcall make_005cedf0(void*, int);
struct X_005cedf0 { X_005cedf0(); };
X_005cedf0::X_005cedf0() { void* p=make_005cedf0(g_arg_005cedf0,27); g_obj_005cedf0.reg(p); tail_005cedf0((void*)&cb_005cedf0); }
X_005cedf0* func_005cedf0() { static X_005cedf0 x; return &x; }
