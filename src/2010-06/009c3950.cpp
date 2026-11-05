// from server: 93% by colin
static const char a[]="IsAggregationShown"; static const char b[]="Debug";
struct C{void m();}; extern void (C::*pmf)(); struct Obj{void run(const char*,const char*,void*,void(C::*)(),int,int,int);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(a,b,(void*)0x4455b0,pmf,0,0xf,0);tail((void*)&e);}
