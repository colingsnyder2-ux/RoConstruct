// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004dd9b0 { void reg(void*); };
extern Obj_004dd9b0 g_obj_004dd9b0;
extern void* g_arg_004dd9b0;
extern void cb_004dd9b0();
extern void tail_004dd9b0(void*);
extern void* __stdcall make_004dd9b0(void*, int);
struct X_004dd9b0 { X_004dd9b0(); };
X_004dd9b0::X_004dd9b0() { void* p=make_004dd9b0(g_arg_004dd9b0,27); g_obj_004dd9b0.reg(p); tail_004dd9b0((void*)&cb_004dd9b0); }
X_004dd9b0* func_004dd9b0() { static X_004dd9b0 x; return &x; }
