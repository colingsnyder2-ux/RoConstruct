// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc540 { void reg(void*); };
extern Obj_005cc540 g_obj_005cc540;
extern void* g_arg_005cc540;
extern void cb_005cc540();
extern void tail_005cc540(void*);
extern void* __stdcall make_005cc540(void*, int);
struct X_005cc540 { X_005cc540(); };
X_005cc540::X_005cc540() { void* p=make_005cc540(g_arg_005cc540,27); g_obj_005cc540.reg(p); tail_005cc540((void*)&cb_005cc540); }
X_005cc540* func_005cc540() { static X_005cc540 x; return &x; }
