// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x124]; int a[1]; void f(int,int); };
void S::f(int i,int v){ if(a[i]!=v) a[i]=v; }
