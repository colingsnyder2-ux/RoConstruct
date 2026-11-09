// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Geometry { public: void update(); };
class ContactConnector { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void step(float dt);
 void f(float dt); char pad[8]; Geometry* g0; Geometry* g1; };
void ContactConnector::f(float dt) { g0->update(); g1->update(); step(dt); } }
