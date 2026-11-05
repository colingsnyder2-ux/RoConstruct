// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b830 { void run(void*,void*,void(*)(),void (Obj_00a1b830::*)(),void (Obj_00a1b830::*)(),int,int); };
extern Obj_00a1b830 obj_00a1b830; extern int p1_00a1b830,p2_00a1b830,e_00a1b830; extern void fn_00a1b830(); extern "C" void tail_00a1b830(void*);
void func_00a1b830() { obj_00a1b830.run(&p1_00a1b830,&p2_00a1b830,fn_00a1b830,(void (Obj_00a1b830::*)())0,(void (Obj_00a1b830::*)())0,31,0); tail_00a1b830(&e_00a1b830); }
