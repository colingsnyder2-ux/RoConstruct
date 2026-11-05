// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cada0 { void reg(void*); };
extern Obj_005cada0 g_obj_005cada0;
extern void* g_arg_005cada0;
extern void cb_005cada0();
extern void tail_005cada0(void*);
extern void* __stdcall make_005cada0(void*, int);
struct X_005cada0 { X_005cada0(); };
X_005cada0::X_005cada0() { void* p=make_005cada0(g_arg_005cada0,27); g_obj_005cada0.reg(p); tail_005cada0((void*)&cb_005cada0); }
X_005cada0* func_005cada0() { static X_005cada0 x; return &x; }
