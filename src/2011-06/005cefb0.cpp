// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cefb0 { void reg(void*); };
extern Obj_005cefb0 g_obj_005cefb0;
extern void* g_arg_005cefb0;
extern void cb_005cefb0();
extern void tail_005cefb0(void*);
extern void* __stdcall make_005cefb0(void*, int);
struct X_005cefb0 { X_005cefb0(); };
X_005cefb0::X_005cefb0() { void* p=make_005cefb0(g_arg_005cefb0,27); g_obj_005cefb0.reg(p); tail_005cefb0((void*)&cb_005cefb0); }
X_005cefb0* func_005cefb0() { static X_005cefb0 x; return &x; }
