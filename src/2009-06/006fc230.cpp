// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct A; struct B; class C;
struct T {
    char d[0x68];
    T(C* owner, B* b);
};
struct Base {
    A* a;
    T* obj;
    B* b;
    Base(A* a, T* obj, B* b) : a(a), obj(obj), b(b) {}
};
class C : public Base {
public:
    C(A* a, B* b);
    virtual ~C();
};
C::C(A* a, B* b) : Base(a, new T(this, b), b) {}
