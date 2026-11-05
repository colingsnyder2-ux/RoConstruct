// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a29960 { void run(void*,void*,void(*)(),void (Obj_00a29960::*)(),void (Obj_00a29960::*)(),int,int); };
extern Obj_00a29960 obj_00a29960; extern int p1_00a29960,p2_00a29960,e_00a29960; extern void fn_00a29960(); extern "C" void tail_00a29960(void*);
void func_00a29960() { obj_00a29960.run(&p1_00a29960,&p2_00a29960,fn_00a29960,(void (Obj_00a29960::*)())0,(void (Obj_00a29960::*)())0,21,0); tail_00a29960(&e_00a29960); }
