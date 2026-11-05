// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" void* make(); struct Obj{void run(void*,void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){void* x=make();obj.run(x,(void*)0x845b4c);*(void**)&obj=(void*)0x845a58;tail((void*)0x800370);}
