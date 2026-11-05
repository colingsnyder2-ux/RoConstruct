// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Geometry { public: int getType(); };
class BallBallContact { public: void step(Geometry* g, int t); void step(Geometry* g); };
void BallBallContact::step(Geometry* g) { step(g, g->getType()); } }
