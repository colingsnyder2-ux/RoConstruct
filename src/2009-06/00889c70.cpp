// from server: 100% by colin
static const char a[]="child"; static const char b[]="ChildRemoved";
struct Obj{void run(int,const char*,const char*);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(0x78,b,a);tail((void*)&e);}
