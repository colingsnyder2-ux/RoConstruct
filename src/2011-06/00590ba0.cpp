// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_00590ba0 { void reg(void*); };
extern Obj_00590ba0 g_obj_00590ba0;
extern void* g_arg_00590ba0;
extern void cb_00590ba0();
extern void tail_00590ba0(void*);
extern void* __stdcall make_00590ba0(void*, int);
struct X_00590ba0 { X_00590ba0(); };
X_00590ba0::X_00590ba0() { void* p=make_00590ba0(g_arg_00590ba0,27); g_obj_00590ba0.reg(p); tail_00590ba0((void*)&cb_00590ba0); }
X_00590ba0* func_00590ba0() { static X_00590ba0 x; return &x; }
