// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2c760 { void run(void*,void*,void(*)(),void (Obj_00a2c760::*)(),void (Obj_00a2c760::*)(),int,int); };
extern Obj_00a2c760 obj_00a2c760; extern int p1_00a2c760,p2_00a2c760,e_00a2c760; extern void fn_00a2c760(); extern "C" void tail_00a2c760(void*);
void func_00a2c760() { obj_00a2c760.run(&p1_00a2c760,&p2_00a2c760,fn_00a2c760,(void (Obj_00a2c760::*)())0,(void (Obj_00a2c760::*)())0,21,0); tail_00a2c760(&e_00a2c760); }
