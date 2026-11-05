// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GS- /EHsc /MD
struct Obj { void reg(void*); };
extern Obj g_obj; extern void* g_arg; extern void cb_fn(); extern void tail(void*);
extern void* __stdcall make(void*,int);
struct X { X(); };
X::X(){ void* p=make(g_arg,27); g_obj.reg(p); tail((void*)&cb_fn); }
unsigned char guard;
X* func_0040e930(){ static X x; return &x; }


