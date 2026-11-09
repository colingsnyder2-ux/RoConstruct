// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d80e0 { void run(void*,void*,void(*)(),void (Obj_009d80e0::*)(),void (Obj_009d80e0::*)(),int,int); };
extern Obj_009d80e0 obj_009d80e0; extern int p1_009d80e0,p2_009d80e0,e_009d80e0; extern void fn_009d80e0(); extern "C" void tail_009d80e0(void*);
void func_009d80e0() { obj_009d80e0.run(&p1_009d80e0,&p2_009d80e0,fn_009d80e0,(void (Obj_009d80e0::*)())0,(void (Obj_009d80e0::*)())0,15,0); tail_009d80e0(&e_009d80e0); }
