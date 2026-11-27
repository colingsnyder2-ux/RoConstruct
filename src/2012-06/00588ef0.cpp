// from server: 95% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct M { M(); int pad[10]; };
struct V { int a, b, c; V() { a = 0; b = 0; c = 0; } ~V(); }; struct R { V v; bool f; unsigned char x : 1; unsigned char y : 1; M m; int idx; R(); }; R::R() { f = false; x = 0; y = 0; idx = -1; }
