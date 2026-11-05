// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ceca0 { void reg(void*); };
extern Obj_005ceca0 g_obj_005ceca0;
extern void* g_arg_005ceca0;
extern void cb_005ceca0();
extern void tail_005ceca0(void*);
extern void* __stdcall make_005ceca0(void*, int);
struct X_005ceca0 { X_005ceca0(); };
X_005ceca0::X_005ceca0() { void* p=make_005ceca0(g_arg_005ceca0,27); g_obj_005ceca0.reg(p); tail_005ceca0((void*)&cb_005ceca0); }
X_005ceca0* func_005ceca0() { static X_005ceca0 x; return &x; }
