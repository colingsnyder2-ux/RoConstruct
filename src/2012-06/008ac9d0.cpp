// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2
#include <string>
struct A { virtual void a(); };
struct B { virtual void b(); };
struct Base : A, B { char pad[0x2c]; Base(int); ~Base(); };
struct D : Base { std::string name; bool flag; float x, y, z; int i, j; D(int a); virtual void a(); virtual void b(); };
D::D(int a) : Base(a), name("ArrowCursor"), flag(false), x(0), y(0), z(0), i(0), j(0) {}
