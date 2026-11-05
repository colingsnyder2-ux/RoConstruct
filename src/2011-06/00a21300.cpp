// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a21300 { void run(void*,void*,void*,void*,void*); }; extern Obj_00a21300 obj_00a21300; extern "C" void tail_00a21300(void*);
void func_00a21300() { obj_00a21300.run((void*)0x5e57f0,0,(void*)0xa8a0c0,(void*)0xa90c84,0); tail_00a21300((void*)0xa39560); }
