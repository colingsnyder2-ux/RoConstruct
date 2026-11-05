// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class Torso { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual float getValue(); };
class Humanoid { char pad[0xd4]; Torso* torso; public: float getValue(); float getValue2(); };
float Humanoid::getValue() { Torso* t = torso; if (t) return t->getValue(); return 0.0f; }
float Humanoid::getValue2() { return torso ? torso->getValue() : 0.0f; }
}
