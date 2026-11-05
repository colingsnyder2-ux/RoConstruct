// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d2360 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009d2360 obj_009d2360; extern int p_a_009d2360,p_b_009d2360,p_c_009d2360,p_d_009d2360,e_009d2360; extern "C" void tail_009d2360(void*);
void func_009d2360() { obj_009d2360.run((void*)&p_d_009d2360,(void*)&p_c_009d2360,(void*)&p_b_009d2360,(void*)&p_a_009d2360,0,15,0); tail_009d2360(&e_009d2360); }
