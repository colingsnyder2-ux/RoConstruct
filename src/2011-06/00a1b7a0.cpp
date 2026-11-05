// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b7a0 { void run(void*,void*,void(*)(),void (Obj_00a1b7a0::*)(),void (Obj_00a1b7a0::*)(),int,int); };
extern Obj_00a1b7a0 obj_00a1b7a0; extern int p1_00a1b7a0,p2_00a1b7a0,e_00a1b7a0; extern void fn_00a1b7a0(); extern "C" void tail_00a1b7a0(void*);
void func_00a1b7a0() { obj_00a1b7a0.run(&p1_00a1b7a0,&p2_00a1b7a0,fn_00a1b7a0,(void (Obj_00a1b7a0::*)())0,(void (Obj_00a1b7a0::*)())0,31,0); tail_00a1b7a0(&e_00a1b7a0); }
