// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a18480 { void run(void*,void*,void(*)(),void (Obj_00a18480::*)(),void (Obj_00a18480::*)(),int,int); };
extern Obj_00a18480 obj_00a18480; extern int p1_00a18480,p2_00a18480,e_00a18480; extern void fn_00a18480(); extern "C" void tail_00a18480(void*);
void func_00a18480() { obj_00a18480.run(&p1_00a18480,&p2_00a18480,fn_00a18480,(void (Obj_00a18480::*)())0,(void (Obj_00a18480::*)())0,21,0); tail_00a18480(&e_00a18480); }
