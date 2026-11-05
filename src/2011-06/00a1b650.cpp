// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b650 { void run(void*,void*,void(*)(),void (Obj_00a1b650::*)(),void (Obj_00a1b650::*)(),int,int); };
extern Obj_00a1b650 obj_00a1b650; extern int p1_00a1b650,p2_00a1b650,e_00a1b650; extern void fn_00a1b650(); extern "C" void tail_00a1b650(void*);
void func_00a1b650() { obj_00a1b650.run(&p1_00a1b650,&p2_00a1b650,fn_00a1b650,(void (Obj_00a1b650::*)())0,(void (Obj_00a1b650::*)())0,31,0); tail_00a1b650(&e_00a1b650); }
