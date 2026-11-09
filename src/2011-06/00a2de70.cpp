// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2de70 { void run(void*,void*,void(*)(),void (Obj_00a2de70::*)(),void (Obj_00a2de70::*)(),int,int); };
extern Obj_00a2de70 obj_00a2de70; extern int p1_00a2de70,p2_00a2de70,e_00a2de70; extern void fn_00a2de70(); extern "C" void tail_00a2de70(void*);
void func_00a2de70() { obj_00a2de70.run(&p1_00a2de70,&p2_00a2de70,fn_00a2de70,(void (Obj_00a2de70::*)())0,(void (Obj_00a2de70::*)())0,31,0); tail_00a2de70(&e_00a2de70); }
