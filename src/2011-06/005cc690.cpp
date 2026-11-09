// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc690 { void reg(void*); };
extern Obj_005cc690 g_obj_005cc690;
extern void* g_arg_005cc690;
extern void cb_005cc690();
extern void tail_005cc690(void*);
extern void* __stdcall make_005cc690(void*, int);
struct X_005cc690 { X_005cc690(); };
X_005cc690::X_005cc690() { void* p=make_005cc690(g_arg_005cc690,27); g_obj_005cc690.reg(p); tail_005cc690((void*)&cb_005cc690); }
X_005cc690* func_005cc690() { static X_005cc690 x; return &x; }
