// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a26d90 { void run(void*,void*,void*,void*,void*); }; extern Obj_00a26d90 obj_00a26d90; extern "C" void tail_00a26d90(void*);
void func_00a26d90() { obj_00a26d90.run((void*)0x689900,0,(void*)0xa9f238,(void*)0xa9f22c,0); tail_00a26d90((void*)0xa3b900); }
