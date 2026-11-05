// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a18a90 { void run(void*,void*,void(*)(),void (Obj_00a18a90::*)(),void (Obj_00a18a90::*)(),int,int); };
extern Obj_00a18a90 obj_00a18a90; extern int p1_00a18a90,p2_00a18a90,e_00a18a90; extern void fn_00a18a90(); extern "C" void tail_00a18a90(void*);
void func_00a18a90() { obj_00a18a90.run(&p1_00a18a90,&p2_00a18a90,fn_00a18a90,(void (Obj_00a18a90::*)())0,(void (Obj_00a18a90::*)())0,21,0); tail_00a18a90(&e_00a18a90); }
