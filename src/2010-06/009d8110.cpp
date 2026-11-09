// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d8110 { void run(void*,void*,void(*)(),void (Obj_009d8110::*)(),void (Obj_009d8110::*)(),int,int); };
extern Obj_009d8110 obj_009d8110; extern int p1_009d8110,p2_009d8110,e_009d8110; extern void fn_009d8110(); extern "C" void tail_009d8110(void*);
void func_009d8110() { obj_009d8110.run(&p1_009d8110,&p2_009d8110,fn_009d8110,(void (Obj_009d8110::*)())0,(void (Obj_009d8110::*)())0,15,0); tail_009d8110(&e_009d8110); }
