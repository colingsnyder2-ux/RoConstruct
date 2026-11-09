// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
static const char a[]="recipient"; static const char b[]="message"; static const char c[]="Chatted";
struct Obj{void run(const char*,const char*,const char*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run(c,b,a);tail((void*)0x778550);}
