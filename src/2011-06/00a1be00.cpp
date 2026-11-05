// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1be00 { void run(void*,void*,void(*)(),void (Obj_00a1be00::*)(),void (Obj_00a1be00::*)(),int,int); };
extern Obj_00a1be00 obj_00a1be00; extern int p1_00a1be00,p2_00a1be00,e_00a1be00; extern void fn_00a1be00(); extern "C" void tail_00a1be00(void*);
void func_00a1be00() { obj_00a1be00.run(&p1_00a1be00,&p2_00a1be00,fn_00a1be00,(void (Obj_00a1be00::*)())0,(void (Obj_00a1be00::*)())0,31,0); tail_00a1be00(&e_00a1be00); }
