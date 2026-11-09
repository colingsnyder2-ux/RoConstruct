// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8d90 { void run(void*,void*,void(*)(),void (Obj_009c8d90::*)(),void (Obj_009c8d90::*)(),int,int); };
extern Obj_009c8d90 obj_009c8d90; extern int p1_009c8d90,p2_009c8d90,e_009c8d90; extern void fn_009c8d90(); extern "C" void tail_009c8d90(void*);
void func_009c8d90() { obj_009c8d90.run(&p1_009c8d90,&p2_009c8d90,fn_009c8d90,(void (Obj_009c8d90::*)())0,(void (Obj_009c8d90::*)())0,15,0); tail_009c8d90(&e_009c8d90); }
