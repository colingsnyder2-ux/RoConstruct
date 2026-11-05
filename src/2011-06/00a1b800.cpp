// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b800 { void run(void*,void*,void(*)(),void (Obj_00a1b800::*)(),void (Obj_00a1b800::*)(),int,int); };
extern Obj_00a1b800 obj_00a1b800; extern int p1_00a1b800,p2_00a1b800,e_00a1b800; extern void fn_00a1b800(); extern "C" void tail_00a1b800(void*);
void func_00a1b800() { obj_00a1b800.run(&p1_00a1b800,&p2_00a1b800,fn_00a1b800,(void (Obj_00a1b800::*)())0,(void (Obj_00a1b800::*)())0,31,0); tail_00a1b800(&e_00a1b800); }
