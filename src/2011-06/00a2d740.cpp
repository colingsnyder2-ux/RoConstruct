// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2d740 { void run(void*,void*,void(*)(),void (Obj_00a2d740::*)(),void (Obj_00a2d740::*)(),int,int); };
extern Obj_00a2d740 obj_00a2d740; extern int p1_00a2d740,p2_00a2d740,e_00a2d740; extern void fn_00a2d740(); extern "C" void tail_00a2d740(void*);
void func_00a2d740() { obj_00a2d740.run(&p1_00a2d740,&p2_00a2d740,fn_00a2d740,(void (Obj_00a2d740::*)())0,(void (Obj_00a2d740::*)())0,21,0); tail_00a2d740(&e_00a2d740); }
