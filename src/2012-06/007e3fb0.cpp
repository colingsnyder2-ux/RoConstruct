// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
int Y(void*, int);
struct A { void* g(); bool f(); int h(); };

bool A::f(){ void* p = g(); return Y(p, 0) ? true : false; }
