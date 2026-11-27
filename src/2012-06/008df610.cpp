// from server: 82% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct V { int go(); };
struct A { char pad[0x1c]; };
struct S2 { int q; };
struct D : A, S2 { char pad2[0x84 - 0x20]; char* e; };
struct X { char pad[0x30]; int a; int b; int f(S2* p); };
int X::f(S2* p) {
  D* d = static_cast<D*>(p);
  char* e = d->e;
  int v = *(int*)(e + b) + a;
  return ((V*)(v + (char*)d + 0x84))->go();
}