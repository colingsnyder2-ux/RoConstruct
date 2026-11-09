// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b980 { void run(void*,void*,void(*)(),void (Obj_00a1b980::*)(),void (Obj_00a1b980::*)(),int,int); };
extern Obj_00a1b980 obj_00a1b980; extern int p1_00a1b980,p2_00a1b980,e_00a1b980; extern void fn_00a1b980(); extern "C" void tail_00a1b980(void*);
void func_00a1b980() { obj_00a1b980.run(&p1_00a1b980,&p2_00a1b980,fn_00a1b980,(void (Obj_00a1b980::*)())0,(void (Obj_00a1b980::*)())0,31,0); tail_00a1b980(&e_00a1b980); }
