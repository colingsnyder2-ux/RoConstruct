// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b560 { void run(void*,void*,void(*)(),void (Obj_00a1b560::*)(),void (Obj_00a1b560::*)(),int,int); };
extern Obj_00a1b560 obj_00a1b560; extern int p1_00a1b560,p2_00a1b560,e_00a1b560; extern void fn_00a1b560(); extern "C" void tail_00a1b560(void*);
void func_00a1b560() { obj_00a1b560.run(&p1_00a1b560,&p2_00a1b560,fn_00a1b560,(void (Obj_00a1b560::*)())0,(void (Obj_00a1b560::*)())0,31,0); tail_00a1b560(&e_00a1b560); }
