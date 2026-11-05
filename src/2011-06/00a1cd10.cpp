// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1cd10 { void run(void*,void*,void(*)(),void (Obj_00a1cd10::*)(),void (Obj_00a1cd10::*)(),int,int); };
extern Obj_00a1cd10 obj_00a1cd10; extern int p1_00a1cd10,p2_00a1cd10,e_00a1cd10; extern void fn_00a1cd10(); extern "C" void tail_00a1cd10(void*);
void func_00a1cd10() { obj_00a1cd10.run(&p1_00a1cd10,&p2_00a1cd10,fn_00a1cd10,(void (Obj_00a1cd10::*)())0,(void (Obj_00a1cd10::*)())0,21,0); tail_00a1cd10(&e_00a1cd10); }
