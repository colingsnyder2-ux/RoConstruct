// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { namespace HUMAN {
class MovingNoPhysicsBase { public: void doMove(float dt, int x); };
class StrafingNoPhysics : public MovingNoPhysicsBase { public: void onStep(float dt, int x); };
void StrafingNoPhysics::onStep(float dt, int x) { doMove(dt, x); }
} }
