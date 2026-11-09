// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2e070 { void run(void*,void*,void(*)(),void (Obj_00a2e070::*)(),void (Obj_00a2e070::*)(),int,int); };
extern Obj_00a2e070 obj_00a2e070; extern int p1_00a2e070,p2_00a2e070,e_00a2e070; extern void fn_00a2e070(); extern "C" void tail_00a2e070(void*);
void func_00a2e070() { obj_00a2e070.run(&p1_00a2e070,&p2_00a2e070,fn_00a2e070,(void (Obj_00a2e070::*)())0,(void (Obj_00a2e070::*)())0,21,0); tail_00a2e070(&e_00a2e070); }
