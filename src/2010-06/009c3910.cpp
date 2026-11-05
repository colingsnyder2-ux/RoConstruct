// from server: 93% by colin
static const char a[]="AlwaysDrawConnectors"; static const char b[]="General";
struct C{void m();}; extern void (C::*pmf)();
struct Obj{void run(const char*,const char*,void*,void(C::*)(),int,int,int);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(a,b,(void*)0x445610,pmf,0,9,0);tail((void*)&e);}
