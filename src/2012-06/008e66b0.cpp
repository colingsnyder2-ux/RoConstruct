// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE
struct S{char pad[0xd8]; float x,y; void f(float a,float b);}; void S::f(float a,float b){ x=a; y=b; }
