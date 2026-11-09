// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Humanoid { char pad[0x1e8]; float a; char p2[0x328-0x1ec]; float b; public: int f() const; };
int Humanoid::f() const { return (1.0f - (1.0f - a) * b) > 0.1f; } }
