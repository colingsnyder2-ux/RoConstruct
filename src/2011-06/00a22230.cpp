// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" void* ctor(void*); extern void* out;
void func_00a22230(){ void* local=(void*)0xa5beca; out=ctor(&local); }
