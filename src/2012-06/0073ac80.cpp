// from server: 88% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Base { Base(); virtual ~Base(); };
struct __declspec(novtable) I1 { virtual void a() = 0; char d[0x10]; };
struct __declspec(novtable) I2 { virtual void b() = 0; };
struct __declspec(novtable) I3 { virtual void c() = 0; char d[8]; int x; char e[0x54]; };
struct __declspec(novtable) I4 { virtual void d4() = 0; };
struct __declspec(novtable) I5 { virtual void d5() = 0; };
int make();
int gCount;
struct D : Base, I1, I2, I3, I4, I5 {
    D();
    virtual void a(); virtual void b(); virtual void c(); virtual void d4(); virtual void d5();
};
D::D() { x = make(); ++gCount; }