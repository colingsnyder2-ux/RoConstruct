// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d81d0 { void run(void*,void*,void(*)(),void (Obj_009d81d0::*)(),void (Obj_009d81d0::*)(),int,int); };
extern Obj_009d81d0 obj_009d81d0; extern int p1_009d81d0,p2_009d81d0,e_009d81d0; extern void fn_009d81d0(); extern "C" void tail_009d81d0(void*);
void func_009d81d0() { obj_009d81d0.run(&p1_009d81d0,&p2_009d81d0,fn_009d81d0,(void (Obj_009d81d0::*)())0,(void (Obj_009d81d0::*)())0,15,0); tail_009d81d0(&e_009d81d0); }
