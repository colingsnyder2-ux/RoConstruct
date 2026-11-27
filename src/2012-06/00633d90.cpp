// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
struct S { virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void f(int a,int b,float* c); void g(int a,int b,float* c); };

void S::g(int a,int b,float* c){ f(a,b,c); *c = fabsf(*c); }
