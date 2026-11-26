// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Vt0 { virtual void f0(); };
struct Vt4 { virtual void f4(); int pad4[4]; };
struct Vt18 { virtual void f18(); };
struct Vt1c { virtual void f1c(); int pad20[2]; int value28; int pad2c[21]; };
struct Vt80 { virtual void f80(); };
struct Vt84 { virtual void f84(); };

struct Base : Vt0, Vt4, Vt18, Vt1c, Vt80, Vt84 {
    Base(int a);
};

struct Guard {
    int value;
    Guard() {}
    ~Guard();
};

int getValue();

struct Derived : Base {
    static int counter;
    Guard guard;
    Derived(int a);
};

Derived::Derived(int a) : Base(a) {
    value28 = getValue();
    ++counter;
}
