// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X { void set(bool); };
struct O { char pad[0x198]; X* x; };
struct T { O* getB(); O* getC(); };
struct HS { T* getT(); void f(bool b); };
void HS::f(bool b) {
    O* o = getT()->getB();
    if (o) o->x->set(!b);
    o = getT()->getC();
    if (o) o->x->set(!b);
}
