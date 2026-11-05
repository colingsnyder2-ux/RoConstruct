// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class __declspec(novtable) VB { public: virtual void vb0(); int v; };
class A0 { public: virtual ~A0(); char p[0x10]; };
class A14 { public: virtual void a14(); };
class A18 { public: virtual void a18(); int p; };
class A20 { public: virtual void a20(); char p[0x68]; };
class A8c { public: virtual void a8c(); };
class P0 : public A0, public A14, public A18, public A20, public A8c, public virtual VB { public: P0(); int q[2]; };
class A9c { public: virtual void a9c(); int p[2]; };
class Aa8 { public: virtual void aa8(); int p[3]; };
class Ab8 : public virtual VB { public: virtual void ab8(); };
class PartLike : public P0, public A9c, public Aa8, public Ab8 {
public:
    PartLike();
    virtual void vb0();
    char pad[0x238 - 0xc0];
};
class BaseLike : public PartLike {
public:
    BaseLike();
    virtual void vb0();
    double d;
    int i;
    char pad[0x250 - 0x244];
};
class Derived : public BaseLike {
public:
    Derived();
    virtual void vb0();
};
Derived::Derived() {}
