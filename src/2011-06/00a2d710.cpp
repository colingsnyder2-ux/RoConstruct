// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2d710 { void run(void*,void*,void(*)(),void (Obj_00a2d710::*)(),void (Obj_00a2d710::*)(),int,int); };
extern Obj_00a2d710 obj_00a2d710; extern int p1_00a2d710,p2_00a2d710,e_00a2d710; extern void fn_00a2d710(); extern "C" void tail_00a2d710(void*);
void func_00a2d710() { obj_00a2d710.run(&p1_00a2d710,&p2_00a2d710,fn_00a2d710,(void (Obj_00a2d710::*)())0,(void (Obj_00a2d710::*)())0,21,0); tail_00a2d710(&e_00a2d710); }
