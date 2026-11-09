// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b920 { void run(void*,void*,void(*)(),void (Obj_00a1b920::*)(),void (Obj_00a1b920::*)(),int,int); };
extern Obj_00a1b920 obj_00a1b920; extern int p1_00a1b920,p2_00a1b920,e_00a1b920; extern void fn_00a1b920(); extern "C" void tail_00a1b920(void*);
void func_00a1b920() { obj_00a1b920.run(&p1_00a1b920,&p2_00a1b920,fn_00a1b920,(void (Obj_00a1b920::*)())0,(void (Obj_00a1b920::*)())0,31,0); tail_00a1b920(&e_00a1b920); }
