// from server: 74% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_009cf620 { void run(void*,void*,void*,void*,int,int,int); };
extern Obj_009cf620 obj_009cf620; extern int p_a_009cf620,p_b_009cf620,p_c_009cf620,p_d_009cf620,e_009cf620; extern "C" void tail_009cf620(void*);
void func_009cf620() { obj_009cf620.run((void*)&p_d_009cf620,(void*)&p_c_009cf620,(void*)&p_b_009cf620,(void*)&p_a_009cf620,0,15,0); tail_009cf620(&e_009cf620); }
