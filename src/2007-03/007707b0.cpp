// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int,int);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run((void*)0x79bfdc,(void*)0x79bfc0,253,5);tail((void*)0x778810);}
