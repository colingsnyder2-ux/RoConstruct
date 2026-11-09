// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8e50 { void run(void*,void*,void(*)(),void (Obj_009c8e50::*)(),void (Obj_009c8e50::*)(),int,int); };
extern Obj_009c8e50 obj_009c8e50; extern int p1_009c8e50,p2_009c8e50,e_009c8e50; extern void fn_009c8e50(); extern "C" void tail_009c8e50(void*);
void func_009c8e50() { obj_009c8e50.run(&p1_009c8e50,&p2_009c8e50,fn_009c8e50,(void (Obj_009c8e50::*)())0,(void (Obj_009c8e50::*)())0,15,0); tail_009c8e50(&e_009c8e50); }
