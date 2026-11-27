// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

struct B { char p[0x20]; void (*fn)(__int64,int); int a; int b; void call(); };
void B::call(){ fn(a,b); }
