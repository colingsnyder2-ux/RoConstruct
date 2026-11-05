// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1ba70 { void run(void*,void*,void(*)(),void (Obj_00a1ba70::*)(),void (Obj_00a1ba70::*)(),int,int); };
extern Obj_00a1ba70 obj_00a1ba70; extern int p1_00a1ba70,p2_00a1ba70,e_00a1ba70; extern void fn_00a1ba70(); extern "C" void tail_00a1ba70(void*);
void func_00a1ba70() { obj_00a1ba70.run(&p1_00a1ba70,&p2_00a1ba70,fn_00a1ba70,(void (Obj_00a1ba70::*)())0,(void (Obj_00a1ba70::*)())0,31,0); tail_00a1ba70(&e_00a1ba70); }
