// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int fn(void*,int);
void func(){ *(volatile int*)0x00973cd4=fn((void*)0x0082d9d8,3001); }
