// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj{void run(void*,void*,int);}; extern Obj obj; extern int a,b,e; extern "C" void tail(void*);
void func(){obj.run((void*)&a,(void*)&b,172);tail((void*)&e);}
