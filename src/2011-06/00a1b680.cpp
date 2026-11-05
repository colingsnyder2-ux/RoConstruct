// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b680 { void run(void*,void*,void(*)(),void (Obj_00a1b680::*)(),void (Obj_00a1b680::*)(),int,int); };
extern Obj_00a1b680 obj_00a1b680; extern int p1_00a1b680,p2_00a1b680,e_00a1b680; extern void fn_00a1b680(); extern "C" void tail_00a1b680(void*);
void func_00a1b680() { obj_00a1b680.run(&p1_00a1b680,&p2_00a1b680,fn_00a1b680,(void (Obj_00a1b680::*)())0,(void (Obj_00a1b680::*)())0,31,0); tail_00a1b680(&e_00a1b680); }
