// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a29bb0 { void run(void (Obj_00a29bb0::*)(),void*,void*,void*,void*,int,int); };
extern Obj_00a29bb0 obj_00a29bb0; extern int p_a_00a29bb0,p_b_00a29bb0,p_c_00a29bb0,p_d_00a29bb0,e_00a29bb0; extern "C" void tail_00a29bb0(void*);
void func_00a29bb0() { obj_00a29bb0.run((void (Obj_00a29bb0::*)())0,(void*)&p_d_00a29bb0,(void*)&p_c_00a29bb0,(void*)&p_b_00a29bb0,(void*)&p_a_00a29bb0,15,0); tail_00a29bb0(&e_00a29bb0); }
