// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class RevoluteLink { public: void reset(); };
class Joint { char pad[0x10]; public: RevoluteLink* link; };
class Pair { char pad[4]; Joint* joint; public: void f(); };
void Pair::f() { if (joint) joint->link->reset(); }
}
