// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct B{void release();}; extern "C" void second(B*);
struct S{char pad[4]; B* p; void f();}; void S::f(){B* q=p;if(q){q->release();second(q);}}
