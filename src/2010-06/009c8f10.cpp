// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8f10 { void run(void*,void*,void(*)(),void (Obj_009c8f10::*)(),void (Obj_009c8f10::*)(),int,int); };
extern Obj_009c8f10 obj_009c8f10; extern int p1_009c8f10,p2_009c8f10,e_009c8f10; extern void fn_009c8f10(); extern "C" void tail_009c8f10(void*);
void func_009c8f10() { obj_009c8f10.run(&p1_009c8f10,&p2_009c8f10,fn_009c8f10,(void (Obj_009c8f10::*)())0,(void (Obj_009c8f10::*)())0,15,0); tail_009c8f10(&e_009c8f10); }
