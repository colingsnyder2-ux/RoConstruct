// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bb90 { void run(void*,void*,void(*)(),void (Obj_00a1bb90::*)(),void (Obj_00a1bb90::*)(),int,int); };
extern Obj_00a1bb90 obj_00a1bb90; extern int p1_00a1bb90,p2_00a1bb90,e_00a1bb90; extern void fn_00a1bb90(); extern "C" void tail_00a1bb90(void*);
void func_00a1bb90() { obj_00a1bb90.run(&p1_00a1bb90,&p2_00a1bb90,fn_00a1bb90,(void (Obj_00a1bb90::*)())0,(void (Obj_00a1bb90::*)())0,31,0); tail_00a1bb90(&e_00a1bb90); }
