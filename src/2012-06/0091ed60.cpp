// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct S{ virtual void v(); float f; S(float a); }; S::S(float a){ f=a; }
