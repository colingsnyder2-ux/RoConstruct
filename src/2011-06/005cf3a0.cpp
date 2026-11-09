// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf3a0 { void reg(void*); };
extern Obj_005cf3a0 g_obj_005cf3a0;
extern void* g_arg_005cf3a0;
extern void cb_005cf3a0();
extern void tail_005cf3a0(void*);
extern void* __stdcall make_005cf3a0(void*, int);
struct X_005cf3a0 { X_005cf3a0(); };
X_005cf3a0::X_005cf3a0() { void* p=make_005cf3a0(g_arg_005cf3a0,27); g_obj_005cf3a0.reg(p); tail_005cf3a0((void*)&cb_005cf3a0); }
X_005cf3a0* func_005cf3a0() { static X_005cf3a0 x; return &x; }
