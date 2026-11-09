// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void first(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.first((void*)0x8331d4,(void*)0x81c960);tail((void*)0x7fdfa0);}
