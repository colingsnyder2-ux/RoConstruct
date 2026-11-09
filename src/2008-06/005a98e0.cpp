// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern void* g;
extern "C" void* a(void*,int,int);
extern "C" void* b(void*,int,void*);
extern "C" void* c(void*,void*,void*);
extern "C" int f(void* p){void* q=a(p,2,0); void* z=b(p,1,g); c(z,q,p); return 0;}
