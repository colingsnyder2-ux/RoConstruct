// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ceae0 { void reg(void*); };
extern Obj_005ceae0 g_obj_005ceae0;
extern void* g_arg_005ceae0;
extern void cb_005ceae0();
extern void tail_005ceae0(void*);
extern void* __stdcall make_005ceae0(void*, int);
struct X_005ceae0 { X_005ceae0(); };
X_005ceae0::X_005ceae0() { void* p=make_005ceae0(g_arg_005ceae0,27); g_obj_005ceae0.reg(p); tail_005ceae0((void*)&cb_005ceae0); }
X_005ceae0* func_005ceae0() { static X_005ceae0 x; return &x; }
