// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1bc50 { void run(void*,void*,void(*)(),void (Obj_00a1bc50::*)(),void (Obj_00a1bc50::*)(),int,int); };
extern Obj_00a1bc50 obj_00a1bc50; extern int p1_00a1bc50,p2_00a1bc50,e_00a1bc50; extern void fn_00a1bc50(); extern "C" void tail_00a1bc50(void*);
void func_00a1bc50() { obj_00a1bc50.run(&p1_00a1bc50,&p2_00a1bc50,fn_00a1bc50,(void (Obj_00a1bc50::*)())0,(void (Obj_00a1bc50::*)())0,31,0); tail_00a1bc50(&e_00a1bc50); }
