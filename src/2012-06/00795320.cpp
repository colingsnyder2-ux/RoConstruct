// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct I{ virtual void v0(); virtual void v1(int); };
struct S{ char p[0xc]; char* q; void f(); }; void S::f(){ char* t=q; if(t) ((I*)(t+4))->v1(1); }
