// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d24c0 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009d24c0 obj_009d24c0; extern int p_a_009d24c0,p_b_009d24c0,p_c_009d24c0,p_d_009d24c0,e_009d24c0; extern "C" void tail_009d24c0(void*);
void func_009d24c0() { obj_009d24c0.run((void*)&p_d_009d24c0,(void*)&p_c_009d24c0,(void*)&p_b_009d24c0,(void*)&p_a_009d24c0,0,15,0); tail_009d24c0(&e_009d24c0); }
