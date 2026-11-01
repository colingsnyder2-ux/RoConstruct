// from server: 100% by EspClaude
// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class PartInstance { char pad[0x130]; public: bool locked; }; PartInstance* getPart(void* p);
bool isUnlocked(void* p) { return getPart(p)->locked == false; } }
