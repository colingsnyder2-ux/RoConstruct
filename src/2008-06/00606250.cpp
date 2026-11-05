// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Primitive { char pad[0x30]; public: bool anchored; };
class ContactConnector { char pad[0x14]; Primitive* p0; Primitive* p1; public: int both() const; };
int ContactConnector::both() const { return p0->anchored && p1->anchored; } }
