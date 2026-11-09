// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bc80 { void run(void*,void*,void(*)(),void (Obj_00a1bc80::*)(),void (Obj_00a1bc80::*)(),int,int); };
extern Obj_00a1bc80 obj_00a1bc80; extern int p1_00a1bc80,p2_00a1bc80,e_00a1bc80; extern void fn_00a1bc80(); extern "C" void tail_00a1bc80(void*);
void func_00a1bc80() { obj_00a1bc80.run(&p1_00a1bc80,&p2_00a1bc80,fn_00a1bc80,(void (Obj_00a1bc80::*)())0,(void (Obj_00a1bc80::*)())0,31,0); tail_00a1bc80(&e_00a1bc80); }
