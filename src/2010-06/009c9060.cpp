// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c9060 { void run(void*,void*,void(*)(),void (Obj_009c9060::*)(),void (Obj_009c9060::*)(),int,int); };
extern Obj_009c9060 obj_009c9060; extern int p1_009c9060,p2_009c9060,e_009c9060; extern void fn_009c9060(); extern "C" void tail_009c9060(void*);
void func_009c9060() { obj_009c9060.run(&p1_009c9060,&p2_009c9060,fn_009c9060,(void (Obj_009c9060::*)())0,(void (Obj_009c9060::*)())0,15,0); tail_009c9060(&e_009c9060); }
