// from server: 92% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern int guard; extern volatile void* slot; extern "C" void base(); extern "C" void reg(void*,void*); extern "C" void* make();
struct Obj{void* run();}; extern "C" Obj* init(void*);
void* f(){slot=(void*)0x0; void* local; if(!guard){base();} else {reg((void*)0xcbe640,(void*)0x5c14d0); local=make();} return init(&local)->run();}
