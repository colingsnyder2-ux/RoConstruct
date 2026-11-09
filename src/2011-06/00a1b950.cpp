// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b950 { void run(void*,void*,void(*)(),void (Obj_00a1b950::*)(),void (Obj_00a1b950::*)(),int,int); };
extern Obj_00a1b950 obj_00a1b950; extern int p1_00a1b950,p2_00a1b950,e_00a1b950; extern void fn_00a1b950(); extern "C" void tail_00a1b950(void*);
void func_00a1b950() { obj_00a1b950.run(&p1_00a1b950,&p2_00a1b950,fn_00a1b950,(void (Obj_00a1b950::*)())0,(void (Obj_00a1b950::*)())0,31,0); tail_00a1b950(&e_00a1b950); }
