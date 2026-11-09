// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf880 { void run(void*,void*,void(*)(),void (Obj_009cf880::*)(),void (Obj_009cf880::*)(),int,int); };
extern Obj_009cf880 obj_009cf880; extern int p1_009cf880,p2_009cf880,e_009cf880; extern void fn_009cf880(); extern "C" void tail_009cf880(void*);
void func_009cf880() { obj_009cf880.run(&p1_009cf880,&p2_009cf880,fn_009cf880,(void (Obj_009cf880::*)())0,(void (Obj_009cf880::*)())0,9,0); tail_009cf880(&e_009cf880); }
