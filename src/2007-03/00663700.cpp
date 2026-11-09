// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct O{char pad[0xfc]; void* value;}; struct G{O* get();}; extern G* g;
void func(void* p){O* o=g->get();o->value=p;}
