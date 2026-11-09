// from server: 100% by colin
static const char a[]="descendant"; static const char b[]="DescendantAdded";
struct Obj{void run(int,const char*,const char*);}; extern Obj obj; extern int e; extern "C" void tail(void*);
void func(){obj.run(0x7c,b,a);tail((void*)&e);}
