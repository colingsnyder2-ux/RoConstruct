// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cca10 { void reg(void*); };
extern Obj_005cca10 g_obj_005cca10;
extern void* g_arg_005cca10;
extern void cb_005cca10();
extern void tail_005cca10(void*);
extern void* __stdcall make_005cca10(void*, int);
struct X_005cca10 { X_005cca10(); };
X_005cca10::X_005cca10() { void* p=make_005cca10(g_arg_005cca10,27); g_obj_005cca10.reg(p); tail_005cca10((void*)&cb_005cca10); }
X_005cca10* func_005cca10() { static X_005cca10 x; return &x; }
