// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005caef0 { void reg(void*); };
extern Obj_005caef0 g_obj_005caef0;
extern void* g_arg_005caef0;
extern void cb_005caef0();
extern void tail_005caef0(void*);
extern void* __stdcall make_005caef0(void*, int);
struct X_005caef0 { X_005caef0(); };
X_005caef0::X_005caef0() { void* p=make_005caef0(g_arg_005caef0,25); g_obj_005caef0.reg(p); tail_005caef0((void*)&cb_005caef0); }
X_005caef0* func_005caef0() { static X_005caef0 x; return &x; }
