// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004dda20 { void reg(void*); };
extern Obj_004dda20 g_obj_004dda20;
extern void* g_arg_004dda20;
extern void cb_004dda20();
extern void tail_004dda20(void*);
extern void* __stdcall make_004dda20(void*, int);
struct X_004dda20 { X_004dda20(); };
X_004dda20::X_004dda20() { void* p=make_004dda20(g_arg_004dda20,27); g_obj_004dda20.reg(p); tail_004dda20((void*)&cb_004dda20); }
X_004dda20* func_004dda20() { static X_004dda20 x; return &x; }
