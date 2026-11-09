// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c9000 { void run(void*,void*,void(*)(),void (Obj_009c9000::*)(),void (Obj_009c9000::*)(),int,int); };
extern Obj_009c9000 obj_009c9000; extern int p1_009c9000,p2_009c9000,e_009c9000; extern void fn_009c9000(); extern "C" void tail_009c9000(void*);
void func_009c9000() { obj_009c9000.run(&p1_009c9000,&p2_009c9000,fn_009c9000,(void (Obj_009c9000::*)())0,(void (Obj_009c9000::*)())0,15,0); tail_009c9000(&e_009c9000); }
