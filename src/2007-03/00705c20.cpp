// from server: 100% by colin
// roc-flags: /O2 /GS- /MD
struct A{void* value; A* get();}; struct S{char pad[0xa8]; A* p; void* f();};
void* S::f(){A* q=p; return q?q->get()->value:0;}
