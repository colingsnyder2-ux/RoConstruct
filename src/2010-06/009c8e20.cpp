// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8e20 { void run(void*,void*,void(*)(),void (Obj_009c8e20::*)(),void (Obj_009c8e20::*)(),int,int); };
extern Obj_009c8e20 obj_009c8e20; extern int p1_009c8e20,p2_009c8e20,e_009c8e20; extern void fn_009c8e20(); extern "C" void tail_009c8e20(void*);
void func_009c8e20() { obj_009c8e20.run(&p1_009c8e20,&p2_009c8e20,fn_009c8e20,(void (Obj_009c8e20::*)())0,(void (Obj_009c8e20::*)())0,15,0); tail_009c8e20(&e_009c8e20); }
