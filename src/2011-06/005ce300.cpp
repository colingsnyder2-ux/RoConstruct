// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ce300 { void reg(void*); };
extern Obj_005ce300 g_obj_005ce300;
extern void* g_arg_005ce300;
extern void cb_005ce300();
extern void tail_005ce300(void*);
extern void* __stdcall make_005ce300(void*, int);
struct X_005ce300 { X_005ce300(); };
X_005ce300::X_005ce300() { void* p=make_005ce300(g_arg_005ce300,27); g_obj_005ce300.reg(p); tail_005ce300((void*)&cb_005ce300); }
X_005ce300* func_005ce300() { static X_005ce300 x; return &x; }
