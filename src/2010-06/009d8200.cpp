// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d8200 { void run(void*,void*,void(*)(),void (Obj_009d8200::*)(),void (Obj_009d8200::*)(),int,int); };
extern Obj_009d8200 obj_009d8200; extern int p1_009d8200,p2_009d8200,e_009d8200; extern void fn_009d8200(); extern "C" void tail_009d8200(void*);
void func_009d8200() { obj_009d8200.run(&p1_009d8200,&p2_009d8200,fn_009d8200,(void (Obj_009d8200::*)())0,(void (Obj_009d8200::*)())0,15,0); tail_009d8200(&e_009d8200); }
