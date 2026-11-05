// from server: 84% by EspClaude
// true extent: 0x20 bytes (server extent 0x2c; swallows next fn at 0x643450)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct B0 { virtual ~B0(); int pad[4]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); int x; };
struct B3 { virtual void f3(); };
struct Base : B0, B1, B2, B3 { virtual ~Base(); };
struct D : Base { virtual ~D(); };
D::~D() {}
