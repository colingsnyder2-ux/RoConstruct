// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a22990 { void run(void (Obj_00a22990::*)(),void*,void*,void*,void*,int,int); };
extern Obj_00a22990 obj_00a22990; extern int p_a_00a22990,p_b_00a22990,p_c_00a22990,p_d_00a22990,e_00a22990; extern "C" void tail_00a22990(void*);
void func_00a22990() { obj_00a22990.run((void (Obj_00a22990::*)())0,(void*)&p_d_00a22990,(void*)&p_c_00a22990,(void*)&p_b_00a22990,(void*)&p_a_00a22990,15,0); tail_00a22990(&e_00a22990); }
