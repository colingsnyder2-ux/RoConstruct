// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc230 { void reg(void*); };
extern Obj_005cc230 g_obj_005cc230;
extern void* g_arg_005cc230;
extern void cb_005cc230();
extern void tail_005cc230(void*);
extern void* __stdcall make_005cc230(void*, int);
struct X_005cc230 { X_005cc230(); };
X_005cc230::X_005cc230() { void* p=make_005cc230(g_arg_005cc230,27); g_obj_005cc230.reg(p); tail_005cc230((void*)&cb_005cc230); }
X_005cc230* func_005cc230() { static X_005cc230 x; return &x; }
