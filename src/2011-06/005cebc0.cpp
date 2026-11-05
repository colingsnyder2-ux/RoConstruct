// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj_005cebc0 { void reg(void*); };
extern Obj_005cebc0 g_obj_005cebc0;
extern void* g_arg_005cebc0;
extern void cb_005cebc0();
extern void tail_005cebc0(void*);
extern void* __stdcall make_005cebc0(void*, int);
struct X_005cebc0 { X_005cebc0(); };
X_005cebc0::X_005cebc0() { void* p=make_005cebc0(g_arg_005cebc0,27); g_obj_005cebc0.reg(p); tail_005cebc0((void*)&cb_005cebc0); }
X_005cebc0* func_005cebc0() { static X_005cebc0 x; return &x; }
