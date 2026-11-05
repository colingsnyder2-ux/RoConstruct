// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8d30 { void run(void*,void*,void(*)(),void (Obj_009c8d30::*)(),void (Obj_009c8d30::*)(),int,int); };
extern Obj_009c8d30 obj_009c8d30; extern int p1_009c8d30,p2_009c8d30,e_009c8d30; extern void fn_009c8d30(); extern "C" void tail_009c8d30(void*);
void func_009c8d30() { obj_009c8d30.run(&p1_009c8d30,&p2_009c8d30,fn_009c8d30,(void (Obj_009c8d30::*)())0,(void (Obj_009c8d30::*)())0,15,0); tail_009c8d30(&e_009c8d30); }
