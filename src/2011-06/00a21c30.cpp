// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a21c30 { void run(void*,void*,void(*)(),void (Obj_00a21c30::*)(),void (Obj_00a21c30::*)(),int,int); };
extern Obj_00a21c30 obj_00a21c30; extern int p1_00a21c30,p2_00a21c30,e_00a21c30; extern void fn_00a21c30(); extern "C" void tail_00a21c30(void*);
void func_00a21c30() { obj_00a21c30.run(&p1_00a21c30,&p2_00a21c30,fn_00a21c30,(void (Obj_00a21c30::*)())0,(void (Obj_00a21c30::*)())0,21,0); tail_00a21c30(&e_00a21c30); }
