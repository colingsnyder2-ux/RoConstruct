// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004b12d0 { void reg(void*); };
extern Obj_004b12d0 g_obj_004b12d0;
extern void* g_arg_004b12d0;
extern void cb_004b12d0();
extern void tail_004b12d0(void*);
extern void* __stdcall make_004b12d0(void*, int);
struct X_004b12d0 { X_004b12d0(); };
X_004b12d0::X_004b12d0() { void* p=make_004b12d0(g_arg_004b12d0,27); g_obj_004b12d0.reg(p); tail_004b12d0((void*)&cb_004b12d0); }
X_004b12d0* func_004b12d0() { static X_004b12d0 x; return &x; }
