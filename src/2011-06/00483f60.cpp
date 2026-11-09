// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_00483f60 { void reg(void*); };
extern Obj_00483f60 g_obj_00483f60;
extern void* g_arg_00483f60;
extern void cb_00483f60();
extern void tail_00483f60(void*);
extern void* __stdcall make_00483f60(void*, int);
struct X_00483f60 { X_00483f60(); };
X_00483f60::X_00483f60() { void* p=make_00483f60(g_arg_00483f60,27); g_obj_00483f60.reg(p); tail_00483f60((void*)&cb_00483f60); }
X_00483f60* func_00483f60() { static X_00483f60 x; return &x; }
