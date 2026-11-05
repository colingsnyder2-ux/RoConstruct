// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf850 { void run(void*,void*,void(*)(),void (Obj_009cf850::*)(),void (Obj_009cf850::*)(),int,int); };
extern Obj_009cf850 obj_009cf850; extern int p1_009cf850,p2_009cf850,e_009cf850; extern void fn_009cf850(); extern "C" void tail_009cf850(void*);
void func_009cf850() { obj_009cf850.run(&p1_009cf850,&p2_009cf850,fn_009cf850,(void (Obj_009cf850::*)())0,(void (Obj_009cf850::*)())0,9,0); tail_009cf850(&e_009cf850); }
