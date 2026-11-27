// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct L; struct P; 
struct X { void go(P*); };
extern P* __cdecl A(L*, int);
extern int __cdecl B(L*, int);
extern void __cdecl Cc(L*, int, int);
extern int __cdecl Dd(L*, int, int);
extern void __cdecl E(L*, int);
extern int gref;
bool f(L* l, int idx, X* x) {
  P* p = A(l, idx);
  if (p && B(l, idx)) {
    Cc(l, -10000, gref);
    if (Dd(l, -1, -2)) { E(l, -3); x->go(p); return true; }
    E(l, -3);
  }
  return false;
}