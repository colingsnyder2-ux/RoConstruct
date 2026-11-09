// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { namespace ViewNew { class ViewRbxGfx { char pad[0x44]; bool a; char pad2[3]; bool b; public: void reset(bool all); };
void ViewRbxGfx::reset(bool all) { a = false; if (all) b = false; } } }
