// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bb30 { void run(void*,void*,void(*)(),void (Obj_00a1bb30::*)(),void (Obj_00a1bb30::*)(),int,int); };
extern Obj_00a1bb30 obj_00a1bb30; extern int p1_00a1bb30,p2_00a1bb30,e_00a1bb30; extern void fn_00a1bb30(); extern "C" void tail_00a1bb30(void*);
void func_00a1bb30() { obj_00a1bb30.run(&p1_00a1bb30,&p2_00a1bb30,fn_00a1bb30,(void (Obj_00a1bb30::*)())0,(void (Obj_00a1bb30::*)())0,31,0); tail_00a1bb30(&e_00a1bb30); }
