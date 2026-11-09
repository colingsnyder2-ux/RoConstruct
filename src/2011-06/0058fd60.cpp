// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_0058fd60 { void reg(void*); };
extern Obj_0058fd60 g_obj_0058fd60;
extern void* g_arg_0058fd60;
extern void cb_0058fd60();
extern void tail_0058fd60(void*);
extern void* __stdcall make_0058fd60(void*, int);
struct X_0058fd60 { X_0058fd60(); };
X_0058fd60::X_0058fd60() { void* p=make_0058fd60(g_arg_0058fd60,27); g_obj_0058fd60.reg(p); tail_0058fd60((void*)&cb_0058fd60); }
X_0058fd60* func_0058fd60() { static X_0058fd60 x; return &x; }
