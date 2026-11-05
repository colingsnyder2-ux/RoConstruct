// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d3510 { void run(void*,void*,void(*)(),void (Obj_009d3510::*)(),void (Obj_009d3510::*)(),int,int); };
extern Obj_009d3510 obj_009d3510; extern int p1_009d3510,p2_009d3510,e_009d3510; extern void fn_009d3510(); extern "C" void tail_009d3510(void*);
void func_009d3510() { obj_009d3510.run(&p1_009d3510,&p2_009d3510,fn_009d3510,(void (Obj_009d3510::*)())0,(void (Obj_009d3510::*)())0,9,0); tail_009d3510(&e_009d3510); }
