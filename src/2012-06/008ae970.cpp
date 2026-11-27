// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE

struct Flag { bool b; float x,y,z; int p,q; Flag(); };
Flag::Flag() : p(0), q(0) { b=true; x=0.0f; y=0.0f; z=0.0f; }
