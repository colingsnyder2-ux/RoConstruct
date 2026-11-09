// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a1ca70 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_00a1ca70 obj_00a1ca70; extern int p_a_00a1ca70,p_b_00a1ca70,p_c_00a1ca70,p_d_00a1ca70,e_00a1ca70; extern "C" void tail_00a1ca70(void*);
void func_00a1ca70() { obj_00a1ca70.run((void*)&p_d_00a1ca70,(void*)&p_c_00a1ca70,(void*)&p_b_00a1ca70,(void*)&p_a_00a1ca70,0,15,0); tail_00a1ca70(&e_00a1ca70); }
