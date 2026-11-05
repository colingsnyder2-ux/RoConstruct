// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8c70 { void run(void*,void*,void(*)(),void (Obj_009c8c70::*)(),void (Obj_009c8c70::*)(),int,int); };
extern Obj_009c8c70 obj_009c8c70; extern int p1_009c8c70,p2_009c8c70,e_009c8c70; extern void fn_009c8c70(); extern "C" void tail_009c8c70(void*);
void func_009c8c70() { obj_009c8c70.run(&p1_009c8c70,&p2_009c8c70,fn_009c8c70,(void (Obj_009c8c70::*)())0,(void (Obj_009c8c70::*)())0,15,0); tail_009c8c70(&e_009c8c70); }
