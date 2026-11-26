// from server: 100% by Xemicl
// roc 2012-06 0089b650  unit: RBX::VHole::?$FactoryProduct  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0089b650
//
// 0089b650  83c108               add ecx, 8
// 0089b653  51                   push ecx
// 0089b654  e85735f9ff           call 0x82ebb0
// 0089b659  83c404               add esp, 4
// 0089b65c  c3                   ret 
// copied from an identical function in another client (function ?step@BlockBlockContact@RBX@@QAE_NXZ)

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