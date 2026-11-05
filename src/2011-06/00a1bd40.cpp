// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bd40 { void run(void*,void*,void(*)(),void (Obj_00a1bd40::*)(),void (Obj_00a1bd40::*)(),int,int); };
extern Obj_00a1bd40 obj_00a1bd40; extern int p1_00a1bd40,p2_00a1bd40,e_00a1bd40; extern void fn_00a1bd40(); extern "C" void tail_00a1bd40(void*);
void func_00a1bd40() { obj_00a1bd40.run(&p1_00a1bd40,&p2_00a1bd40,fn_00a1bd40,(void (Obj_00a1bd40::*)())0,(void (Obj_00a1bd40::*)())0,31,0); tail_00a1bd40(&e_00a1bd40); }
