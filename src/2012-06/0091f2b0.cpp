// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct A0 { virtual void a0(); char pad[0x18]; };
struct A1 { virtual void a1(); };
struct A : A0, A1 { A(); };
struct C : A {
    C(int arg);
    void init(int arg);
    virtual void a0();
    virtual void a1();
};
C::C(int arg) { init(arg); }
