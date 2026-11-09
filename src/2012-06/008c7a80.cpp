// from server: 100% by tajop
struct SS {
    char d[0x88];
    void ctor(int mode, int most);
};
extern void (SS::*g_ssctor)(int, int);

struct Holder {
    int p;
    Holder() : p(0) {}
    ~Holder();
};

struct P0 { virtual ~P0(); virtual void f0(); };
struct P1 { virtual void f1(); char p1[0x10]; };
struct P2 { virtual void f2(); };
struct P3 { virtual void f3(); };

struct FuncDescBase : P0, P1, P2, P3 {
    FuncDescBase();
    char basePad[0x60];
};

struct FuncDesc : FuncDescBase {
    bool flag;
    FuncDesc() : flag(true) {}
};

struct BoundFuncDesc : FuncDesc {
    Holder function;
    SS stream;
    int count;
    double value;
    BoundFuncDesc();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

BoundFuncDesc::BoundFuncDesc()
    : function()
{
    (stream.*g_ssctor)(3, 1);
    value = 0.0;
    count = 0;
}
