// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bc20 { void run(void*,void*,void(*)(),void (Obj_00a1bc20::*)(),void (Obj_00a1bc20::*)(),int,int); };
extern Obj_00a1bc20 obj_00a1bc20; extern int p1_00a1bc20,p2_00a1bc20,e_00a1bc20; extern void fn_00a1bc20(); extern "C" void tail_00a1bc20(void*);
void func_00a1bc20() { obj_00a1bc20.run(&p1_00a1bc20,&p2_00a1bc20,fn_00a1bc20,(void (Obj_00a1bc20::*)())0,(void (Obj_00a1bc20::*)())0,31,0); tail_00a1bc20(&e_00a1bc20); }
