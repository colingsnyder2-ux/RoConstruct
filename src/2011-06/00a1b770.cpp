// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b770 { void run(void*,void*,void(*)(),void (Obj_00a1b770::*)(),void (Obj_00a1b770::*)(),int,int); };
extern Obj_00a1b770 obj_00a1b770; extern int p1_00a1b770,p2_00a1b770,e_00a1b770; extern void fn_00a1b770(); extern "C" void tail_00a1b770(void*);
void func_00a1b770() { obj_00a1b770.run(&p1_00a1b770,&p2_00a1b770,fn_00a1b770,(void (Obj_00a1b770::*)())0,(void (Obj_00a1b770::*)())0,31,0); tail_00a1b770(&e_00a1b770); }
