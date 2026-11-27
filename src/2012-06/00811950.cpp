// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { void g(float,float,float); };
struct Q { char pad[0x14]; float x,y,z; };
struct S { void f(const Q* q); };
void S::f(const Q* q) { (*(Base**)((char*)this - 4))->g(q->x, q->y, q->z); }
