// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a27340 { void run(void*,void*,void(*)(),void (Obj_00a27340::*)(),void (Obj_00a27340::*)(),int,int); };
extern Obj_00a27340 obj_00a27340; extern int p1_00a27340,p2_00a27340,e_00a27340; extern void fn_00a27340(); extern "C" void tail_00a27340(void*);
void func_00a27340() { obj_00a27340.run(&p1_00a27340,&p2_00a27340,fn_00a27340,(void (Obj_00a27340::*)())0,(void (Obj_00a27340::*)())0,21,0); tail_00a27340(&e_00a27340); }
