// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cb0b0 { void reg(void*); };
extern Obj_005cb0b0 g_obj_005cb0b0;
extern void* g_arg_005cb0b0;
extern void cb_005cb0b0();
extern void tail_005cb0b0(void*);
extern void* __stdcall make_005cb0b0(void*, int);
struct X_005cb0b0 { X_005cb0b0(); };
X_005cb0b0::X_005cb0b0() { void* p=make_005cb0b0(g_arg_005cb0b0,27); g_obj_005cb0b0.reg(p); tail_005cb0b0((void*)&cb_005cb0b0); }
X_005cb0b0* func_005cb0b0() { static X_005cb0b0 x; return &x; }
