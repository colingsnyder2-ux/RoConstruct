// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int,int);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run((void*)0x79a7a0,(void*)0x79a770,389,4);tail((void*)0x778110);}
