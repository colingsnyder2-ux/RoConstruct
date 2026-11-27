// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2
struct B { void init(); char pad[0x30]; };
struct T : B { float a,b,c; T* f(); };
T* T::f(){ init(); a=0.0f; b=0.0f; c=0.0f; return this; }
