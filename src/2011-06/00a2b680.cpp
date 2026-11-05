// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a2b680 { void run(void (Obj_00a2b680::*)(),void*,void*,void*,void*,int,int); };
extern Obj_00a2b680 obj_00a2b680; extern int p_a_00a2b680,p_b_00a2b680,p_c_00a2b680,p_d_00a2b680,e_00a2b680; extern "C" void tail_00a2b680(void*);
void func_00a2b680() { obj_00a2b680.run((void (Obj_00a2b680::*)())0,(void*)&p_d_00a2b680,(void*)&p_c_00a2b680,(void*)&p_b_00a2b680,(void*)&p_a_00a2b680,15,0); tail_00a2b680(&e_00a2b680); }
