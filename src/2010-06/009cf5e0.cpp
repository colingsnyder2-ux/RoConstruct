// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf5e0 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009cf5e0 obj_009cf5e0; extern int p_a_009cf5e0,p_b_009cf5e0,p_c_009cf5e0,p_d_009cf5e0,e_009cf5e0; extern "C" void tail_009cf5e0(void*);
void func_009cf5e0() { obj_009cf5e0.run((void*)&p_d_009cf5e0,(void*)&p_c_009cf5e0,(void*)&p_b_009cf5e0,(void*)&p_a_009cf5e0,0,15,0); tail_009cf5e0(&e_009cf5e0); }
