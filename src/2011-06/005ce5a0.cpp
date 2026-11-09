// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce5a0 { void reg(void*); };
extern Obj_005ce5a0 g_obj_005ce5a0;
extern void* g_arg_005ce5a0;
extern void cb_005ce5a0();
extern void tail_005ce5a0(void*);
extern void* __stdcall make_005ce5a0(void*, int);
struct X_005ce5a0 { X_005ce5a0(); };
X_005ce5a0::X_005ce5a0() { void* p=make_005ce5a0(g_arg_005ce5a0,27); g_obj_005ce5a0.reg(p); tail_005ce5a0((void*)&cb_005ce5a0); }
X_005ce5a0* func_005ce5a0() { static X_005ce5a0 x; return &x; }
