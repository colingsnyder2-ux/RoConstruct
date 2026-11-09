// from server: 86% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf230 { void run(void (Obj_009cf230::*)(),void*,void*,void*,void*,int,int); };
extern Obj_009cf230 obj_009cf230; extern int p_a_009cf230,p_b_009cf230,p_c_009cf230,p_d_009cf230,e_009cf230; extern "C" void tail_009cf230(void*);
void func_009cf230() { obj_009cf230.run((void (Obj_009cf230::*)())0,(void*)&p_d_009cf230,(void*)&p_c_009cf230,(void*)&p_b_009cf230,(void*)&p_a_009cf230,15,0); tail_009cf230(&e_009cf230); }
