// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1b890 { void run(void*,void*,void(*)(),void (Obj_00a1b890::*)(),void (Obj_00a1b890::*)(),int,int); };
extern Obj_00a1b890 obj_00a1b890; extern int p1_00a1b890,p2_00a1b890,e_00a1b890; extern void fn_00a1b890(); extern "C" void tail_00a1b890(void*);
void func_00a1b890() { obj_00a1b890.run(&p1_00a1b890,&p2_00a1b890,fn_00a1b890,(void (Obj_00a1b890::*)())0,(void (Obj_00a1b890::*)())0,31,0); tail_00a1b890(&e_00a1b890); }
