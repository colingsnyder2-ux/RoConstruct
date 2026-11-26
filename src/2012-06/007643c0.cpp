// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct T{int a,b,c; __declspec(dllimport) void g();}; void f(T x){ x.g(); }
