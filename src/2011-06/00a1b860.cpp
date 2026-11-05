// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b860 { void run(void*,void*,void(*)(),void (Obj_00a1b860::*)(),void (Obj_00a1b860::*)(),int,int); };
extern Obj_00a1b860 obj_00a1b860; extern int p1_00a1b860,p2_00a1b860,e_00a1b860; extern void fn_00a1b860(); extern "C" void tail_00a1b860(void*);
void func_00a1b860() { obj_00a1b860.run(&p1_00a1b860,&p2_00a1b860,fn_00a1b860,(void (Obj_00a1b860::*)())0,(void (Obj_00a1b860::*)())0,31,0); tail_00a1b860(&e_00a1b860); }
