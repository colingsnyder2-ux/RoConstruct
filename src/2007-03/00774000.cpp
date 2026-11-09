// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int,int);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run((void*)0x7b3c38,(void*)0x78a128,254,5);tail((void*)0x77ab60);}
