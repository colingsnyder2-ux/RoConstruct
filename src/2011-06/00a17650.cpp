// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a17650 { void run(void*,void*,void(*)(),void (Obj_00a17650::*)(),void (Obj_00a17650::*)(),int,int); };
extern Obj_00a17650 obj_00a17650; extern int p1_00a17650,p2_00a17650,e_00a17650; extern void fn_00a17650(); extern "C" void tail_00a17650(void*);
void func_00a17650() { obj_00a17650.run(&p1_00a17650,&p2_00a17650,fn_00a17650,(void (Obj_00a17650::*)())0,(void (Obj_00a17650::*)())0,21,0); tail_00a17650(&e_00a17650); }
