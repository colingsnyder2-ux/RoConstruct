// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d8140 { void run(void*,void*,void(*)(),void (Obj_009d8140::*)(),void (Obj_009d8140::*)(),int,int); };
extern Obj_009d8140 obj_009d8140; extern int p1_009d8140,p2_009d8140,e_009d8140; extern void fn_009d8140(); extern "C" void tail_009d8140(void*);
void func_009d8140() { obj_009d8140.run(&p1_009d8140,&p2_009d8140,fn_009d8140,(void (Obj_009d8140::*)())0,(void (Obj_009d8140::*)())0,15,0); tail_009d8140(&e_009d8140); }
