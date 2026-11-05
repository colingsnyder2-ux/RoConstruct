// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009d4c70 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009d4c70 obj_009d4c70; extern int p_a_009d4c70,p_b_009d4c70,p_c_009d4c70,p_d_009d4c70,e_009d4c70; extern "C" void tail_009d4c70(void*);
void func_009d4c70() { obj_009d4c70.run((void*)&p_d_009d4c70,(void*)&p_c_009d4c70,(void*)&p_b_009d4c70,(void*)&p_a_009d4c70,0,15,0); tail_009d4c70(&e_009d4c70); }
