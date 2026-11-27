// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct P { int a; short b; P() : a(1), b(0) {} };
P f() { static P p; return p; }
