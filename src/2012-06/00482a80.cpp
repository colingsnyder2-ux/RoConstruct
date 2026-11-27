// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct M{ int a; bool q(int); }; struct S{ int x; int y; int p; char pad[0x44]; M m; bool f(); };
bool S::f(){ if(!m.a) return false; return m.q(p); }
