// from server: 72% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
struct Obj_00a25b30 { void run(void*,void*,void*,void*,void*); }; extern Obj_00a25b30 obj_00a25b30; extern "C" void tail_00a25b30(void*);
void func_00a25b30() { obj_00a25b30.run((void*)0x675cc0,0,(void*)0xa9d4bc,(void*)0xa9d49c,0); tail_00a25b30((void*)0xa3b300); }
