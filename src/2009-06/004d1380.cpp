// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct X {
    int d[15];
    X(const X&);
    ~X();
};
struct Value { X t; };
struct Storage1 { Value a1; };
struct List1 : Storage1 {};
struct P {
    void (*f)();
    List1 l;
};
class Target {
public:
    void post(P p);
};
class C {
    Target* t;
public:
    void post(P p);
};
void C::post(P p)
{
    if (t)
        t->post(p);
}
