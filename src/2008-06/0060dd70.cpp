// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
struct Geom { int a; };
bool doStep(Geom* g);
class BlockBlockContact { char pad[8]; Geom g; public: bool step(); };
bool BlockBlockContact::step() { return doStep(&g); }
}
