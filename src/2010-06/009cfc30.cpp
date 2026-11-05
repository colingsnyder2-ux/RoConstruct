// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cfc30 { void run(void*,void*,void(*)(),void (Obj_009cfc30::*)(),void (Obj_009cfc30::*)(),int,int); };
extern Obj_009cfc30 obj_009cfc30; extern int p1_009cfc30,p2_009cfc30,e_009cfc30; extern void fn_009cfc30(); extern "C" void tail_009cfc30(void*);
void func_009cfc30() { obj_009cfc30.run(&p1_009cfc30,&p2_009cfc30,fn_009cfc30,(void (Obj_009cfc30::*)())0,(void (Obj_009cfc30::*)())0,15,0); tail_009cfc30(&e_009cfc30); }
