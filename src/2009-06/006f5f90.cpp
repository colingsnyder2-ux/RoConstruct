// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern "C" void __stdcall first(void*); extern "C" void second(void*);
struct S{void f(unsigned int);}; void S::f(unsigned int value){first((void*)value); second((void*)value);}
