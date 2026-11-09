// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d79f0 { void run(void*,void*,void(*)(),void (Obj_009d79f0::*)(),void (Obj_009d79f0::*)(),int,int); };
extern Obj_009d79f0 obj_009d79f0; extern int p1_009d79f0,p2_009d79f0,e_009d79f0; extern void fn_009d79f0(); extern "C" void tail_009d79f0(void*);
void func_009d79f0() { obj_009d79f0.run(&p1_009d79f0,&p2_009d79f0,fn_009d79f0,(void (Obj_009d79f0::*)())0,(void (Obj_009d79f0::*)())0,9,0); tail_009d79f0(&e_009d79f0); }
