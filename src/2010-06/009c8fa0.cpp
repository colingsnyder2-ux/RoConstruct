// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8fa0 { void run(void*,void*,void(*)(),void (Obj_009c8fa0::*)(),void (Obj_009c8fa0::*)(),int,int); };
extern Obj_009c8fa0 obj_009c8fa0; extern int p1_009c8fa0,p2_009c8fa0,e_009c8fa0; extern void fn_009c8fa0(); extern "C" void tail_009c8fa0(void*);
void func_009c8fa0() { obj_009c8fa0.run(&p1_009c8fa0,&p2_009c8fa0,fn_009c8fa0,(void (Obj_009c8fa0::*)())0,(void (Obj_009c8fa0::*)())0,15,0); tail_009c8fa0(&e_009c8fa0); }
