// from server: 88% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cea00 { void run(void (Obj_009cea00::*)(),void*,void*,void*,void*,int,int); };
extern Obj_009cea00 obj_009cea00; extern int p_a_009cea00,p_b_009cea00,p_c_009cea00,p_d_009cea00,e_009cea00; extern "C" void tail_009cea00(void*);
void func_009cea00() { obj_009cea00.run((void (Obj_009cea00::*)())0,(void*)&p_d_009cea00,(void*)&p_c_009cea00,(void*)&p_b_009cea00,(void*)&p_a_009cea00,15,0); tail_009cea00(&e_009cea00); }
