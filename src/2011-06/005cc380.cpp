// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cc380 { void reg(void*); };
extern Obj_005cc380 g_obj_005cc380;
extern void* g_arg_005cc380;
extern void cb_005cc380();
extern void tail_005cc380(void*);
extern void* __stdcall make_005cc380(void*, int);
struct X_005cc380 { X_005cc380(); };
X_005cc380::X_005cc380() { void* p=make_005cc380(g_arg_005cc380,27); g_obj_005cc380.reg(p); tail_005cc380((void*)&cb_005cc380); }
X_005cc380* func_005cc380() { static X_005cc380 x; return &x; }
