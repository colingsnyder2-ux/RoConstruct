// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d8170 { void run(void*,void*,void(*)(),void (Obj_009d8170::*)(),void (Obj_009d8170::*)(),int,int); };
extern Obj_009d8170 obj_009d8170; extern int p1_009d8170,p2_009d8170,e_009d8170; extern void fn_009d8170(); extern "C" void tail_009d8170(void*);
void func_009d8170() { obj_009d8170.run(&p1_009d8170,&p2_009d8170,fn_009d8170,(void (Obj_009d8170::*)())0,(void (Obj_009d8170::*)())0,15,0); tail_009d8170(&e_009d8170); }
