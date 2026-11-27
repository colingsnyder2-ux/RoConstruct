// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct S{ char p[0x3c]; char b[0x200]; void f(int i,char v); }; void S::f(int i,char v){ if(i>=0 && (unsigned)i<0x200) b[i]=v; }
