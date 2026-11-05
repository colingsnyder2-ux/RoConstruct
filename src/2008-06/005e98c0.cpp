// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class PartInstance; class Set { public: void insert(PartInstance* const& p); };
class PhysicsService { char pad[0x8c]; Set a; char p2[0x98-0x8d]; Set b; public: void f(PartInstance* x, PartInstance* y); };
void PhysicsService::f(PartInstance* x, PartInstance* y) { a.insert(x); b.insert(y); } }
