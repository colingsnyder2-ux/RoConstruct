// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8c40 { void run(void*,void*,void(*)(),void (Obj_009c8c40::*)(),void (Obj_009c8c40::*)(),int,int); };
extern Obj_009c8c40 obj_009c8c40; extern int p1_009c8c40,p2_009c8c40,e_009c8c40; extern void fn_009c8c40(); extern "C" void tail_009c8c40(void*);
void func_009c8c40() { obj_009c8c40.run(&p1_009c8c40,&p2_009c8c40,fn_009c8c40,(void (Obj_009c8c40::*)())0,(void (Obj_009c8c40::*)())0,15,0); tail_009c8c40(&e_009c8c40); }
