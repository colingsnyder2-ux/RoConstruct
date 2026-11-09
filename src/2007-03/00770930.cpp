// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
static const char a[]="lostConnection"; static const char b[]="peer"; static const char c[]="Disconnection";
struct Obj{void run(const char*,const char*,const char*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run(c,b,a);tail((void*)0x778b90);}
