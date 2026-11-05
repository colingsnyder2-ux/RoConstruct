// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf660 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009cf660 obj_009cf660; extern int p_a_009cf660,p_b_009cf660,p_c_009cf660,p_d_009cf660,e_009cf660; extern "C" void tail_009cf660(void*);
void func_009cf660() { obj_009cf660.run((void*)&p_d_009cf660,(void*)&p_c_009cf660,(void*)&p_b_009cf660,(void*)&p_a_009cf660,0,15,0); tail_009cf660(&e_009cf660); }
