// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c9090 { void run(void*,void*,void(*)(),void (Obj_009c9090::*)(),void (Obj_009c9090::*)(),int,int); };
extern Obj_009c9090 obj_009c9090; extern int p1_009c9090,p2_009c9090,e_009c9090; extern void fn_009c9090(); extern "C" void tail_009c9090(void*);
void func_009c9090() { obj_009c9090.run(&p1_009c9090,&p2_009c9090,fn_009c9090,(void (Obj_009c9090::*)())0,(void (Obj_009c9090::*)())0,15,0); tail_009c9090(&e_009c9090); }
