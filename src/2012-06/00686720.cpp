// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /fp:fast /GS- /EHsc /MD
struct P{ float p0,x,p2,y; }; struct S{ char pad[0x160]; float k; float m(const P* a); };
float S::m(const P* a){ return (a->y - a->x)*k; }
