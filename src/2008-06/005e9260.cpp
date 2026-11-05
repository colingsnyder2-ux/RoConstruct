// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Q { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void add(int x); };
class PhysicsService { char pad[0x88]; Q* q; char p2[0xe8-0x8c]; int n; public: void f(int x); };
void PhysicsService::f(int x) { q->add(x); ++n; } }
