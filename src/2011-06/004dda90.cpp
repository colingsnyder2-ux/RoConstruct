// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_004dda90 { void reg(void*); };
extern Obj_004dda90 g_obj_004dda90;
extern void* g_arg_004dda90;
extern void cb_004dda90();
extern void tail_004dda90(void*);
extern void* __stdcall make_004dda90(void*, int);
struct X_004dda90 { X_004dda90(); };
X_004dda90::X_004dda90() { void* p=make_004dda90(g_arg_004dda90,27); g_obj_004dda90.reg(p); tail_004dda90((void*)&cb_004dda90); }
X_004dda90* func_004dda90() { static X_004dda90 x; return &x; }
