// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc000 { void reg(void*); };
extern Obj_005cc000 g_obj_005cc000;
extern void* g_arg_005cc000;
extern void cb_005cc000();
extern void tail_005cc000(void*);
extern void* __stdcall make_005cc000(void*, int);
struct X_005cc000 { X_005cc000(); };
X_005cc000::X_005cc000() { void* p=make_005cc000(g_arg_005cc000,27); g_obj_005cc000.reg(p); tail_005cc000((void*)&cb_005cc000); }
X_005cc000* func_005cc000() { static X_005cc000 x; return &x; }
