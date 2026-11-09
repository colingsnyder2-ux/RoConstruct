// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
static const char a[]="reason"; static const char b[]="code"; static const char c[]="peer"; static const char d[]="ConnectionFailed";
struct Obj{void run(const void*,const void*,const void*,const void*,const void*,const void*,const void*);}; extern Obj obj; extern "C" void tail(void*);
void func(){obj.run((void*)0x144,d,c,b,a,(void*)0,(void*)1);tail((void*)0x9dd0a0);}
