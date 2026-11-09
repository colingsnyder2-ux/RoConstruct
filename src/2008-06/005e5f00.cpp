// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class MotorJoint { char pad[0xa8]; bool a, b, c; public: int isActive() const; };
int MotorJoint::isActive() const { return a || b || c; } }
