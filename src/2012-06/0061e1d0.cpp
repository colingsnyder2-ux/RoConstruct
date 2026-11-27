// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /arch:SSE /GS- /EHsc /MD
struct B{ B(int); char pad[0x28]; }; struct S:B{ float f; S(int a); };
S::S(int a):B(a){ f=0; }
