// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b710 { void run(void*,void*,void(*)(),void (Obj_00a1b710::*)(),void (Obj_00a1b710::*)(),int,int); };
extern Obj_00a1b710 obj_00a1b710; extern int p1_00a1b710,p2_00a1b710,e_00a1b710; extern void fn_00a1b710(); extern "C" void tail_00a1b710(void*);
void func_00a1b710() { obj_00a1b710.run(&p1_00a1b710,&p2_00a1b710,fn_00a1b710,(void (Obj_00a1b710::*)())0,(void (Obj_00a1b710::*)())0,31,0); tail_00a1b710(&e_00a1b710); }
