// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct I { virtual void v0(int, float, float); };
struct Obj { char pad[8]; I i; int pad2; int x; };
void f(Obj* o, int a, float x, float y) { if (o->x) o->i.v0(a, x, y); }
