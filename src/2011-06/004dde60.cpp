// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004dde60 { void reg(void*); };
extern Obj_004dde60 g_obj_004dde60;
extern void* g_arg_004dde60;
extern void cb_004dde60();
extern void tail_004dde60(void*);
extern void* __stdcall make_004dde60(void*, int);
struct X_004dde60 { X_004dde60(); };
X_004dde60::X_004dde60() { void* p=make_004dde60(g_arg_004dde60,27); g_obj_004dde60.reg(p); tail_004dde60((void*)&cb_004dde60); }
X_004dde60* func_004dde60() { static X_004dde60 x; return &x; }
