// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct B1 { B1(int, int); virtual void f0(); char pad[0x1c]; };
struct __declspec(novtable) I { virtual void i0() = 0; char pad[0xe8]; };
struct __declspec(novtable) J { virtual void j0() = 0; char pad[0x18]; };
struct D : B1, I, J {
    int a; int b;
    D(int x, int y) : B1(x, y) { b = 0; a = 0; }
    virtual void f0(); virtual void i0(); virtual void j0();
};
D g(1,2);
