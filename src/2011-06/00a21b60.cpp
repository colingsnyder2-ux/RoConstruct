// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a21b60 { void run(void*,void*,void(*)(),void (Obj_00a21b60::*)(),void (Obj_00a21b60::*)(),int,int); };
extern Obj_00a21b60 obj_00a21b60; extern int p1_00a21b60,p2_00a21b60,e_00a21b60; extern void fn_00a21b60(); extern "C" void tail_00a21b60(void*);
void func_00a21b60() { obj_00a21b60.run(&p1_00a21b60,&p2_00a21b60,fn_00a21b60,(void (Obj_00a21b60::*)())0,(void (Obj_00a21b60::*)())0,21,0); tail_00a21b60(&e_00a21b60); }
