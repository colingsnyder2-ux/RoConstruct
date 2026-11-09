// from server: 88% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d52e0 { void run(void (Obj_009d52e0::*)(),void*,void*,void*,void*,int,int); };
extern Obj_009d52e0 obj_009d52e0; extern int p_a_009d52e0,p_b_009d52e0,p_c_009d52e0,p_d_009d52e0,e_009d52e0; extern "C" void tail_009d52e0(void*);
void func_009d52e0() { obj_009d52e0.run((void (Obj_009d52e0::*)())0,(void*)&p_d_009d52e0,(void*)&p_c_009d52e0,(void*)&p_b_009d52e0,(void*)&p_a_009d52e0,15,0); tail_009d52e0(&e_009d52e0); }
