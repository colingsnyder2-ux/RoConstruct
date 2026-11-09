// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc620 { void reg(void*); };
extern Obj_005cc620 g_obj_005cc620;
extern void* g_arg_005cc620;
extern void cb_005cc620();
extern void tail_005cc620(void*);
extern void* __stdcall make_005cc620(void*, int);
struct X_005cc620 { X_005cc620(); };
X_005cc620::X_005cc620() { void* p=make_005cc620(g_arg_005cc620,27); g_obj_005cc620.reg(p); tail_005cc620((void*)&cb_005cc620); }
X_005cc620* func_005cc620() { static X_005cc620 x; return &x; }
