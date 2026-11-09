// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cee60 { void reg(void*); };
extern Obj_005cee60 g_obj_005cee60;
extern void* g_arg_005cee60;
extern void cb_005cee60();
extern void tail_005cee60(void*);
extern void* __stdcall make_005cee60(void*, int);
struct X_005cee60 { X_005cee60(); };
X_005cee60::X_005cee60() { void* p=make_005cee60(g_arg_005cee60,27); g_obj_005cee60.reg(p); tail_005cee60((void*)&cb_005cee60); }
X_005cee60* func_005cee60() { static X_005cee60 x; return &x; }
