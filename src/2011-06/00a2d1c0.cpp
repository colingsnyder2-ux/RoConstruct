// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,void*,void*,void*,void*);}; extern Obj obj; extern int a,b,c,d,e; extern "C" void tail(void*);
void func(){obj.run((void*)0xab2194,(void*)&a,(void*)&b,(void*)&c,(void*)0x1f,(void*)0x0);tail((void*)&e);}
