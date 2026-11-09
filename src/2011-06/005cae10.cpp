// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cae10 { void reg(void*); };
extern Obj_005cae10 g_obj_005cae10;
extern void* g_arg_005cae10;
extern void cb_005cae10();
extern void tail_005cae10(void*);
extern void* __stdcall make_005cae10(void*, int);
struct X_005cae10 { X_005cae10(); };
X_005cae10::X_005cae10() { void* p=make_005cae10(g_arg_005cae10,27); g_obj_005cae10.reg(p); tail_005cae10((void*)&cb_005cae10); }
X_005cae10* func_005cae10() { static X_005cae10 x; return &x; }
