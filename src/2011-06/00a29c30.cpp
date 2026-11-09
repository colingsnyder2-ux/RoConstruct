// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a29c30 { void run(void (Obj_00a29c30::*)(),void*,void*,void*,void*,int,int); };
extern Obj_00a29c30 obj_00a29c30; extern int p_a_00a29c30,p_b_00a29c30,p_c_00a29c30,p_d_00a29c30,e_00a29c30; extern "C" void tail_00a29c30(void*);
void func_00a29c30() { obj_00a29c30.run((void (Obj_00a29c30::*)())0,(void*)&p_d_00a29c30,(void*)&p_c_00a29c30,(void*)&p_b_00a29c30,(void*)&p_a_00a29c30,15,0); tail_00a29c30(&e_00a29c30); }
