// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cf480 { void reg(void*); };
extern Obj_005cf480 g_obj_005cf480;
extern void* g_arg_005cf480;
extern void cb_005cf480();
extern void tail_005cf480(void*);
extern void* __stdcall make_005cf480(void*, int);
struct X_005cf480 { X_005cf480(); };
X_005cf480::X_005cf480() { void* p=make_005cf480(g_arg_005cf480,27); g_obj_005cf480.reg(p); tail_005cf480((void*)&cb_005cf480); }
X_005cf480* func_005cf480() { static X_005cf480 x; return &x; }
