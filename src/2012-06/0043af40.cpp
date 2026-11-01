// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
extern "C" void __stdcall first(int); extern "C" void second(int*);
struct S{char pad[12]; int* value; void f();}; void S::f(){int* p=value;if(p){first(*p);second(p);}}
