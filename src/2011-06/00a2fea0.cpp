// from server: 92% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern int guard; extern volatile void* slot;
extern "C" void base(); extern "C" void reg(void*,void*); extern "C" void* make();
struct Obj{void* run();}; extern "C" Obj* init(void*);
void* f(){ slot=(void*)0xa5b684; void* local; if(!guard){base();} else {reg((void*)0x4016b0,(void*)0xcb14f0); local=make();} return init(&local)->run(); }
