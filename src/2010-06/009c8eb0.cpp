// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8eb0 { void run(void*,void*,void(*)(),void (Obj_009c8eb0::*)(),void (Obj_009c8eb0::*)(),int,int); };
extern Obj_009c8eb0 obj_009c8eb0; extern int p1_009c8eb0,p2_009c8eb0,e_009c8eb0; extern void fn_009c8eb0(); extern "C" void tail_009c8eb0(void*);
void func_009c8eb0() { obj_009c8eb0.run(&p1_009c8eb0,&p2_009c8eb0,fn_009c8eb0,(void (Obj_009c8eb0::*)())0,(void (Obj_009c8eb0::*)())0,15,0); tail_009c8eb0(&e_009c8eb0); }
