// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int a, b, c; char d; S(); };
S::S() { c = 0; a = 0; b = 0; d = 0; }