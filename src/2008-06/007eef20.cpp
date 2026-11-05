// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void first(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.first((void*)0x80f118,(void*)0x80f08c);tail((void*)0x7fa760);}
