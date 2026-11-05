// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd490 { void reg(void*); };
extern Obj_005cd490 g_obj_005cd490;
extern void* g_arg_005cd490;
extern void cb_005cd490();
extern void tail_005cd490(void*);
extern void* __stdcall make_005cd490(void*, int);
struct X_005cd490 { X_005cd490(); };
X_005cd490::X_005cd490() { void* p=make_005cd490(g_arg_005cd490,27); g_obj_005cd490.reg(p); tail_005cd490((void*)&cb_005cd490); }
X_005cd490* func_005cd490() { static X_005cd490 x; return &x; }
