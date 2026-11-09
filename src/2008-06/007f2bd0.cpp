// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int fn(void*,int);
void func(){ *(volatile int*)0x00973ec4=fn((void*)0x0080f7cc,3000); }
