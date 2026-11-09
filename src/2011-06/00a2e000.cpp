// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2e000 { void run(void*,void*,void(*)(),void (Obj_00a2e000::*)(),void (Obj_00a2e000::*)(),int,int); };
extern Obj_00a2e000 obj_00a2e000; extern int p1_00a2e000,p2_00a2e000,e_00a2e000; extern void fn_00a2e000(); extern "C" void tail_00a2e000(void*);
void func_00a2e000() { obj_00a2e000.run(&p1_00a2e000,&p2_00a2e000,fn_00a2e000,(void (Obj_00a2e000::*)())0,(void (Obj_00a2e000::*)())0,31,0); tail_00a2e000(&e_00a2e000); }
