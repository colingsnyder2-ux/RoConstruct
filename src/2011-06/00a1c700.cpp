// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1c700 { void run(void*,void*,void(*)(),void (Obj_00a1c700::*)(),void (Obj_00a1c700::*)(),int,int); };
extern Obj_00a1c700 obj_00a1c700; extern int p1_00a1c700,p2_00a1c700,e_00a1c700; extern void fn_00a1c700(); extern "C" void tail_00a1c700(void*);
void func_00a1c700() { obj_00a1c700.run(&p1_00a1c700,&p2_00a1c700,fn_00a1c700,(void (Obj_00a1c700::*)())0,(void (Obj_00a1c700::*)())0,16,0); tail_00a1c700(&e_00a1c700); }
