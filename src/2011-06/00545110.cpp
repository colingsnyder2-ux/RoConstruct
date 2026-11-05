// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct A{char pad[0x50]; int val;}; struct S{char pad[0x2c]; bool flag; char pad2[3]; int value; A* get(); void f(int);};
void S::f(int v){value=v; A* p=get(); flag=v!=p->val;}
