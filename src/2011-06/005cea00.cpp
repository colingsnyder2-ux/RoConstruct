// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cea00 { void reg(void*); };
extern Obj_005cea00 g_obj_005cea00;
extern void* g_arg_005cea00;
extern void cb_005cea00();
extern void tail_005cea00(void*);
extern void* __stdcall make_005cea00(void*, int);
struct X_005cea00 { X_005cea00(); };
X_005cea00::X_005cea00() { void* p=make_005cea00(g_arg_005cea00,27); g_obj_005cea00.reg(p); tail_005cea00((void*)&cb_005cea00); }
X_005cea00* func_005cea00() { static X_005cea00 x; return &x; }
