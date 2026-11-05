// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2c730 { void run(void*,void*,void(*)(),void (Obj_00a2c730::*)(),void (Obj_00a2c730::*)(),int,int); };
extern Obj_00a2c730 obj_00a2c730; extern int p1_00a2c730,p2_00a2c730,e_00a2c730; extern void fn_00a2c730(); extern "C" void tail_00a2c730(void*);
void func_00a2c730() { obj_00a2c730.run(&p1_00a2c730,&p2_00a2c730,fn_00a2c730,(void (Obj_00a2c730::*)())0,(void (Obj_00a2c730::*)())0,21,0); tail_00a2c730(&e_00a2c730); }
