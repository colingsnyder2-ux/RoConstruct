// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009c8f70 { void run(void*,void*,void(*)(),void (Obj_009c8f70::*)(),void (Obj_009c8f70::*)(),int,int); };
extern Obj_009c8f70 obj_009c8f70; extern int p1_009c8f70,p2_009c8f70,e_009c8f70; extern void fn_009c8f70(); extern "C" void tail_009c8f70(void*);
void func_009c8f70() { obj_009c8f70.run(&p1_009c8f70,&p2_009c8f70,fn_009c8f70,(void (Obj_009c8f70::*)())0,(void (Obj_009c8f70::*)())0,15,0); tail_009c8f70(&e_009c8f70); }
