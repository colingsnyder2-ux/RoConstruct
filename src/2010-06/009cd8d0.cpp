// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern int g; extern "C" void f(void*);
void func(){g=0x0; f((void*)0x9df250);}
