// from server: 100% by tajop
struct Vt0 { virtual void f0(); };
struct Vt4 { virtual void f4(); int pad4[4]; };
struct Vt18 { virtual void f18(); };
struct Vt1c { virtual void f1c(); int pad20[2]; int value28; int pad2c[21]; };
struct Vt80 { virtual void f80(); };

struct RelativePanelBase : Vt0, Vt4, Vt18, Vt1c, Vt80 {
    RelativePanelBase();
};

struct Guard {
    int value;
    Guard() {}
    ~Guard();
};

int getValue();

struct NonFactoryProduct : RelativePanelBase {
    static int counter;
    Guard guard;
    NonFactoryProduct();
};

NonFactoryProduct::NonFactoryProduct() {
    value28 = getValue();
    ++counter;
}
