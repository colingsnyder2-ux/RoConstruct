// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a27310 { void run(void*,void*,void(*)(),void (Obj_00a27310::*)(),void (Obj_00a27310::*)(),int,int); };
extern Obj_00a27310 obj_00a27310; extern int p1_00a27310,p2_00a27310,e_00a27310; extern void fn_00a27310(); extern "C" void tail_00a27310(void*);
void func_00a27310() { obj_00a27310.run(&p1_00a27310,&p2_00a27310,fn_00a27310,(void (Obj_00a27310::*)())0,(void (Obj_00a27310::*)())0,21,0); tail_00a27310(&e_00a27310); }
