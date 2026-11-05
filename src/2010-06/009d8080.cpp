// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d8080 { void run(void*,void*,void(*)(),void (Obj_009d8080::*)(),void (Obj_009d8080::*)(),int,int); };
extern Obj_009d8080 obj_009d8080; extern int p1_009d8080,p2_009d8080,e_009d8080; extern void fn_009d8080(); extern "C" void tail_009d8080(void*);
void func_009d8080() { obj_009d8080.run(&p1_009d8080,&p2_009d8080,fn_009d8080,(void (Obj_009d8080::*)())0,(void (Obj_009d8080::*)())0,15,0); tail_009d8080(&e_009d8080); }
