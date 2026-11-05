// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a21b90 { void run(void*,void*,void(*)(),void (Obj_00a21b90::*)(),void (Obj_00a21b90::*)(),int,int); };
extern Obj_00a21b90 obj_00a21b90; extern int p1_00a21b90,p2_00a21b90,e_00a21b90; extern void fn_00a21b90(); extern "C" void tail_00a21b90(void*);
void func_00a21b90() { obj_00a21b90.run(&p1_00a21b90,&p2_00a21b90,fn_00a21b90,(void (Obj_00a21b90::*)())0,(void (Obj_00a21b90::*)())0,21,0); tail_00a21b90(&e_00a21b90); }
