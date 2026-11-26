// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
struct M{ M(); }; struct A{ int x; int a; int b; M m; A():a(0),b(-1){} }; A* k(void*p){return new(p) A;}
