// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d6a80 { void run(void*,void*,void(*)(),void (Obj_009d6a80::*)(),void (Obj_009d6a80::*)(),int,int); };
extern Obj_009d6a80 obj_009d6a80; extern int p1_009d6a80,p2_009d6a80,e_009d6a80; extern void fn_009d6a80(); extern "C" void tail_009d6a80(void*);
void func_009d6a80() { obj_009d6a80.run(&p1_009d6a80,&p2_009d6a80,fn_009d6a80,(void (Obj_009d6a80::*)())0,(void (Obj_009d6a80::*)())0,15,0); tail_009d6a80(&e_009d6a80); }
