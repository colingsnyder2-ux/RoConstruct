// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void first(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.first((void*)0x7879f8,(void*)0x787980);tail((void*)0x777540);}
