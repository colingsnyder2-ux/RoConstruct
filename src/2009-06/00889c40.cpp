// from server: 100% by colin
static const char a[]="child"; static const char b[]="ChildAdded";
struct Obj{void run(int,const char*,const char*);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(0x74,b,a);tail((void*)&e);}
