// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004e6430 { void reg(void*); };
extern Obj_004e6430 g_obj_004e6430;
extern void* g_arg_004e6430;
extern void cb_004e6430();
extern void tail_004e6430(void*);
extern void* __stdcall make_004e6430(void*, int);
struct X_004e6430 { X_004e6430(); };
X_004e6430::X_004e6430() { void* p=make_004e6430(g_arg_004e6430,27); g_obj_004e6430.reg(p); tail_004e6430((void*)&cb_004e6430); }
X_004e6430* func_004e6430() { static X_004e6430 x; return &x; }
