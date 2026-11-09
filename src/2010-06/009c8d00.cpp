// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8d00 { void run(void*,void*,void(*)(),void (Obj_009c8d00::*)(),void (Obj_009c8d00::*)(),int,int); };
extern Obj_009c8d00 obj_009c8d00; extern int p1_009c8d00,p2_009c8d00,e_009c8d00; extern void fn_009c8d00(); extern "C" void tail_009c8d00(void*);
void func_009c8d00() { obj_009c8d00.run(&p1_009c8d00,&p2_009c8d00,fn_009c8d00,(void (Obj_009c8d00::*)())0,(void (Obj_009c8d00::*)())0,15,0); tail_009c8d00(&e_009c8d00); }
