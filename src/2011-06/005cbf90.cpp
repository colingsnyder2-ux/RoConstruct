// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbf90 { void reg(void*); };
extern Obj_005cbf90 g_obj_005cbf90;
extern void* g_arg_005cbf90;
extern void cb_005cbf90();
extern void tail_005cbf90(void*);
extern void* __stdcall make_005cbf90(void*, int);
struct X_005cbf90 { X_005cbf90(); };
X_005cbf90::X_005cbf90() { void* p=make_005cbf90(g_arg_005cbf90,27); g_obj_005cbf90.reg(p); tail_005cbf90((void*)&cb_005cbf90); }
X_005cbf90* func_005cbf90() { static X_005cbf90 x; return &x; }
