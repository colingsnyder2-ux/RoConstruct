// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class Body { public: float getBranchMass() const; };
class RevoluteLink { char pad[0x28]; Body* body; char pad2[0x8c-0x2c]; float mass; public: float getMass() const; };
float RevoluteLink::getMass() const { if (body) return body->getBranchMass(); return mass; }
}
