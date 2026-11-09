// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0040ec90 { void reg(void*); };
extern Obj_0040ec90 g_obj_0040ec90;
extern void* g_arg_0040ec90;
extern void cb_0040ec90();
extern void tail_0040ec90(void*);
extern void* __stdcall make_0040ec90(void*, int);
struct X_0040ec90 { X_0040ec90(); };
X_0040ec90::X_0040ec90() { void* p=make_0040ec90(g_arg_0040ec90,27); g_obj_0040ec90.reg(p); tail_0040ec90((void*)&cb_0040ec90); }
X_0040ec90* func_0040ec90() { static X_0040ec90 x; return &x; }
