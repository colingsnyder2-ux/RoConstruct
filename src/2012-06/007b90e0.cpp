// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct S{ char p[0x10]; float v; void f(float* o,int); }; void S::f(float* o,int){ float t=v; o[0]=t; o[1]=t; o[2]=t; }
