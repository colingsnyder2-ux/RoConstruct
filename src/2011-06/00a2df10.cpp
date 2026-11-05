// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2df10 { void run(void*,void*,void(*)(),void (Obj_00a2df10::*)(),void (Obj_00a2df10::*)(),int,int); };
extern Obj_00a2df10 obj_00a2df10; extern int p1_00a2df10,p2_00a2df10,e_00a2df10; extern void fn_00a2df10(); extern "C" void tail_00a2df10(void*);
void func_00a2df10() { obj_00a2df10.run(&p1_00a2df10,&p2_00a2df10,fn_00a2df10,(void (Obj_00a2df10::*)())0,(void (Obj_00a2df10::*)())0,31,0); tail_00a2df10(&e_00a2df10); }
