// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004ddca0 { void reg(void*); };
extern Obj_004ddca0 g_obj_004ddca0;
extern void* g_arg_004ddca0;
extern void cb_004ddca0();
extern void tail_004ddca0(void*);
extern void* __stdcall make_004ddca0(void*, int);
struct X_004ddca0 { X_004ddca0(); };
X_004ddca0::X_004ddca0() { void* p=make_004ddca0(g_arg_004ddca0,27); g_obj_004ddca0.reg(p); tail_004ddca0((void*)&cb_004ddca0); }
X_004ddca0* func_004ddca0() { static X_004ddca0 x; return &x; }
