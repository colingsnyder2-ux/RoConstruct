// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a29930 { void run(void*,void*,void(*)(),void (Obj_00a29930::*)(),void (Obj_00a29930::*)(),int,int); };
extern Obj_00a29930 obj_00a29930; extern int p1_00a29930,p2_00a29930,e_00a29930; extern void fn_00a29930(); extern "C" void tail_00a29930(void*);
void func_00a29930() { obj_00a29930.run(&p1_00a29930,&p2_00a29930,fn_00a29930,(void (Obj_00a29930::*)())0,(void (Obj_00a29930::*)())0,21,0); tail_00a29930(&e_00a29930); }
