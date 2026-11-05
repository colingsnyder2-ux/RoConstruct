// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cbd60 { void reg(void*); };
extern Obj_005cbd60 g_obj_005cbd60;
extern void* g_arg_005cbd60;
extern void cb_005cbd60();
extern void tail_005cbd60(void*);
extern void* __stdcall make_005cbd60(void*, int);
struct X_005cbd60 { X_005cbd60(); };
X_005cbd60::X_005cbd60() { void* p=make_005cbd60(g_arg_005cbd60,27); g_obj_005cbd60.reg(p); tail_005cbd60((void*)&cb_005cbd60); }
X_005cbd60* func_005cbd60() { static X_005cbd60 x; return &x; }
