// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
void h(void*,int); struct S{ char pad[0x1c]; int f; S* m(int a,int b); };
S* S::m(int a,int b){ h(this,a); f=b; return this; }
