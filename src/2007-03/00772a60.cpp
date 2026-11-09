// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int fn(void*,int);
void func(){ *(volatile int*)0x008bcc24=fn((void*)0x007ac6a4,1001); }
