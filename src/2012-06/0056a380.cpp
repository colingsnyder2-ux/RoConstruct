// from server: 80% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct R { int a; int b; R(){} R(const R& o):a(o.a),b(o.b){} };
struct S { char pad[0x234]; int flag; R f(int); };
R S::f(int) { double d = !flag ? 1.5 : 0.0; return *(R*)&d; }
