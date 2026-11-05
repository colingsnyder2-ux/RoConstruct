// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c9030 { void run(void*,void*,void(*)(),void (Obj_009c9030::*)(),void (Obj_009c9030::*)(),int,int); };
extern Obj_009c9030 obj_009c9030; extern int p1_009c9030,p2_009c9030,e_009c9030; extern void fn_009c9030(); extern "C" void tail_009c9030(void*);
void func_009c9030() { obj_009c9030.run(&p1_009c9030,&p2_009c9030,fn_009c9030,(void (Obj_009c9030::*)())0,(void (Obj_009c9030::*)())0,15,0); tail_009c9030(&e_009c9030); }
