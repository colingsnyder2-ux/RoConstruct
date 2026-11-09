// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040efc0 { void reg(void*); };
extern Obj_0040efc0 g_obj_0040efc0;
extern void* g_arg_0040efc0;
extern void cb_0040efc0();
extern void tail_0040efc0(void*);
extern void* __stdcall make_0040efc0(void*, int);
struct X_0040efc0 { X_0040efc0(); };
X_0040efc0::X_0040efc0() { void* p=make_0040efc0(g_arg_0040efc0,27); g_obj_0040efc0.reg(p); tail_0040efc0((void*)&cb_0040efc0); }
X_0040efc0* func_0040efc0() { static X_0040efc0 x; return &x; }
