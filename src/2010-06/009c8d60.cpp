// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8d60 { void run(void*,void*,void(*)(),void (Obj_009c8d60::*)(),void (Obj_009c8d60::*)(),int,int); };
extern Obj_009c8d60 obj_009c8d60; extern int p1_009c8d60,p2_009c8d60,e_009c8d60; extern void fn_009c8d60(); extern "C" void tail_009c8d60(void*);
void func_009c8d60() { obj_009c8d60.run(&p1_009c8d60,&p2_009c8d60,fn_009c8d60,(void (Obj_009c8d60::*)())0,(void (Obj_009c8d60::*)())0,15,0); tail_009c8d60(&e_009c8d60); }
