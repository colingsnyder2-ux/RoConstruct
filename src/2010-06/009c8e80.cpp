// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8e80 { void run(void*,void*,void(*)(),void (Obj_009c8e80::*)(),void (Obj_009c8e80::*)(),int,int); };
extern Obj_009c8e80 obj_009c8e80; extern int p1_009c8e80,p2_009c8e80,e_009c8e80; extern void fn_009c8e80(); extern "C" void tail_009c8e80(void*);
void func_009c8e80() { obj_009c8e80.run(&p1_009c8e80,&p2_009c8e80,fn_009c8e80,(void (Obj_009c8e80::*)())0,(void (Obj_009c8e80::*)())0,15,0); tail_009c8e80(&e_009c8e80); }
