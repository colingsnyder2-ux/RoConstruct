// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern unsigned count; extern void* ptr; extern "C" void call(void*);
void func(){if(count>0)call(ptr);}
