// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005ced10 { void reg(void*); };
extern Obj_005ced10 g_obj_005ced10;
extern void* g_arg_005ced10;
extern void cb_005ced10();
extern void tail_005ced10(void*);
extern void* __stdcall make_005ced10(void*, int);
struct X_005ced10 { X_005ced10(); };
X_005ced10::X_005ced10() { void* p=make_005ced10(g_arg_005ced10,27); g_obj_005ced10.reg(p); tail_005ced10((void*)&cb_005ced10); }
X_005ced10* func_005ced10() { static X_005ced10 x; return &x; }
