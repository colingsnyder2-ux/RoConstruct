// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a184f0 { void run(void*,void*,void(*)(),void (Obj_00a184f0::*)(),void (Obj_00a184f0::*)(),int,int); };
extern Obj_00a184f0 obj_00a184f0; extern int p1_00a184f0,p2_00a184f0,e_00a184f0; extern void fn_00a184f0(); extern "C" void tail_00a184f0(void*);
void func_00a184f0() { obj_00a184f0.run(&p1_00a184f0,&p2_00a184f0,fn_00a184f0,(void (Obj_00a184f0::*)())0,(void (Obj_00a184f0::*)())0,16,0); tail_00a184f0(&e_00a184f0); }
