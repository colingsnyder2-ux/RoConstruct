// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d2500 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009d2500 obj_009d2500; extern int p_a_009d2500,p_b_009d2500,p_c_009d2500,p_d_009d2500,e_009d2500; extern "C" void tail_009d2500(void*);
void func_009d2500() { obj_009d2500.run((void*)&p_d_009d2500,(void*)&p_c_009d2500,(void*)&p_b_009d2500,(void*)&p_a_009d2500,0,15,0); tail_009d2500(&e_009d2500); }
