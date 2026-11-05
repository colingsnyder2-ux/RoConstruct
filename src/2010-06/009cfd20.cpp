// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cfd20 { void run(void*,void*,void(*)(),void (Obj_009cfd20::*)(),void (Obj_009cfd20::*)(),int,int); };
extern Obj_009cfd20 obj_009cfd20; extern int p1_009cfd20,p2_009cfd20,e_009cfd20; extern void fn_009cfd20(); extern "C" void tail_009cfd20(void*);
void func_009cfd20() { obj_009cfd20.run(&p1_009cfd20,&p2_009cfd20,fn_009cfd20,(void (Obj_009cfd20::*)())0,(void (Obj_009cfd20::*)())0,15,0); tail_009cfd20(&e_009cfd20); }
