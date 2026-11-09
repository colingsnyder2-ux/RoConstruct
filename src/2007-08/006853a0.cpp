// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I{void method(int,int);}; struct O{char pad[0x40]; I* p; void f(int,int,int);};
void O::f(int a,int b,int c){p->method(b,c);}
