// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbc10 { void reg(void*); };
extern Obj_005cbc10 g_obj_005cbc10;
extern void* g_arg_005cbc10;
extern void cb_005cbc10();
extern void tail_005cbc10(void*);
extern void* __stdcall make_005cbc10(void*, int);
struct X_005cbc10 { X_005cbc10(); };
X_005cbc10::X_005cbc10() { void* p=make_005cbc10(g_arg_005cbc10,27); g_obj_005cbc10.reg(p); tail_005cbc10((void*)&cb_005cbc10); }
X_005cbc10* func_005cbc10() { static X_005cbc10 x; return &x; }
