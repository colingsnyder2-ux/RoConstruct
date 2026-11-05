// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,void*,void*,void*,void*,void*);}; extern Obj obj; extern int a,b,c,d,e,f; extern "C" void tail(void*);
void func(){obj.run((void*)0x20c,(void*)&a,(void*)&b,(void*)&c,(void*)&d,(void*)&e,(void*)0x2);tail((void*)&f);}
