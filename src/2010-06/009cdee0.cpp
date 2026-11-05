// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cdee0 { void run(void*,void*,void(*)(),void (Obj_009cdee0::*)(),void (Obj_009cdee0::*)(),int,int); };
extern Obj_009cdee0 obj_009cdee0; extern int p1_009cdee0,p2_009cdee0,e_009cdee0; extern void fn_009cdee0(); extern "C" void tail_009cdee0(void*);
void func_009cdee0() { obj_009cdee0.run(&p1_009cdee0,&p2_009cdee0,fn_009cdee0,(void (Obj_009cdee0::*)())0,(void (Obj_009cdee0::*)())0,15,0); tail_009cdee0(&e_009cdee0); }
