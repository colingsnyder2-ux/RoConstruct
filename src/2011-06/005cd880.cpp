// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cd880 { void reg(void*); };
extern Obj_005cd880 g_obj_005cd880;
extern void* g_arg_005cd880;
extern void cb_005cd880();
extern void tail_005cd880(void*);
extern void* __stdcall make_005cd880(void*, int);
struct X_005cd880 { X_005cd880(); };
X_005cd880::X_005cd880() { void* p=make_005cd880(g_arg_005cd880,27); g_obj_005cd880.reg(p); tail_005cd880((void*)&cb_005cd880); }
X_005cd880* func_005cd880() { static X_005cd880 x; return &x; }
