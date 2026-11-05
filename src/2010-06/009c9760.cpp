// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c9760 { void run(void*,void*,void(*)(),void (Obj_009c9760::*)(),void (Obj_009c9760::*)(),int,int); };
extern Obj_009c9760 obj_009c9760; extern int p1_009c9760,p2_009c9760,e_009c9760; extern void fn_009c9760(); extern "C" void tail_009c9760(void*);
void func_009c9760() { obj_009c9760.run(&p1_009c9760,&p2_009c9760,fn_009c9760,(void (Obj_009c9760::*)())0,(void (Obj_009c9760::*)())0,9,0); tail_009c9760(&e_009c9760); }
