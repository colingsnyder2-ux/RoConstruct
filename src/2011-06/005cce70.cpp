// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cce70 { void reg(void*); };
extern Obj_005cce70 g_obj_005cce70;
extern void* g_arg_005cce70;
extern void cb_005cce70();
extern void tail_005cce70(void*);
extern void* __stdcall make_005cce70(void*, int);
struct X_005cce70 { X_005cce70(); };
X_005cce70::X_005cce70() { void* p=make_005cce70(g_arg_005cce70,3); g_obj_005cce70.reg(p); tail_005cce70((void*)&cb_005cce70); }
X_005cce70* func_005cce70() { static X_005cce70 x; return &x; }
