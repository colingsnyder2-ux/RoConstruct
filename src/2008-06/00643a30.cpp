// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { namespace HUMAN { class Landed { public: float getRatio(); bool a(); bool b(); };
bool Landed::a() { if (getRatio() < 0.85f) return true; return false; }
bool Landed::b() { if (getRatio() > 0.9f) return true; else return false; } } }
