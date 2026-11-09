// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1be60 { void run(void*,void*,void(*)(),void (Obj_00a1be60::*)(),void (Obj_00a1be60::*)(),int,int); };
extern Obj_00a1be60 obj_00a1be60; extern int p1_00a1be60,p2_00a1be60,e_00a1be60; extern void fn_00a1be60(); extern "C" void tail_00a1be60(void*);
void func_00a1be60() { obj_00a1be60.run(&p1_00a1be60,&p2_00a1be60,fn_00a1be60,(void (Obj_00a1be60::*)())0,(void (Obj_00a1be60::*)())0,31,0); tail_00a1be60(&e_00a1be60); }
