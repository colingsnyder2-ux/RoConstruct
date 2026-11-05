// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2e270 { void run(void*,void*,void(*)(),void (Obj_00a2e270::*)(),void (Obj_00a2e270::*)(),int,int); };
extern Obj_00a2e270 obj_00a2e270; extern int p1_00a2e270,p2_00a2e270,e_00a2e270; extern void fn_00a2e270(); extern "C" void tail_00a2e270(void*);
void func_00a2e270() { obj_00a2e270.run(&p1_00a2e270,&p2_00a2e270,fn_00a2e270,(void (Obj_00a2e270::*)())0,(void (Obj_00a2e270::*)())0,21,0); tail_00a2e270(&e_00a2e270); }
