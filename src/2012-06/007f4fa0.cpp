// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
struct S{ char p[0x20]; float v; bool f(); }; bool S::f(){ return 4.5f > v; }
