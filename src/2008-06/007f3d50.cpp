// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
extern "C" int fn(void*,int);
void func(){ *(volatile int*)0x00975430=fn((void*)0x009481e8,2000); }
