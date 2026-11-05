// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class PartInstance { char pad[0x2d0]; bool a; char p2[2]; bool b; public: int canX() const; };
int PartInstance::canX() const { return !a && !b; } }
