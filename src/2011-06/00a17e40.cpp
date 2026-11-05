// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a17e40 { void run(void*,void*,void(*)(),void (Obj_00a17e40::*)(),void (Obj_00a17e40::*)(),int,int); };
extern Obj_00a17e40 obj_00a17e40; extern int p1_00a17e40,p2_00a17e40,e_00a17e40; extern void fn_00a17e40(); extern "C" void tail_00a17e40(void*);
void func_00a17e40() { obj_00a17e40.run(&p1_00a17e40,&p2_00a17e40,fn_00a17e40,(void (Obj_00a17e40::*)())0,(void (Obj_00a17e40::*)())0,21,0); tail_00a17e40(&e_00a17e40); }
