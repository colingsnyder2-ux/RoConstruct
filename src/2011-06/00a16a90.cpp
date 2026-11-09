// from server: 93% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
static const char a[]="x"; static const char b[]="y";
struct C{void m();}; extern void (C::*pmf)();
struct Obj{void run(const char*,const char*,void*,void(C::*)(),int,int,int);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(a,b,(void*)0x457650,pmf,0,0x1f,0);tail((void*)&e);}
