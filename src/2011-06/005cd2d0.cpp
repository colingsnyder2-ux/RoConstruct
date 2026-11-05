// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd2d0 { void reg(void*); };
extern Obj_005cd2d0 g_obj_005cd2d0;
extern void* g_arg_005cd2d0;
extern void cb_005cd2d0();
extern void tail_005cd2d0(void*);
extern void* __stdcall make_005cd2d0(void*, int);
struct X_005cd2d0 { X_005cd2d0(); };
X_005cd2d0::X_005cd2d0() { void* p=make_005cd2d0(g_arg_005cd2d0,3); g_obj_005cd2d0.reg(p); tail_005cd2d0((void*)&cb_005cd2d0); }
X_005cd2d0* func_005cd2d0() { static X_005cd2d0 x; return &x; }
