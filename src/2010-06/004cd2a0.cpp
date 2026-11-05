// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct A{char pad[0x94]; void* value;}; extern "C" A* get(void*);
void* func(void* x){A* p=get(x); return p ? p->value : 0;}
