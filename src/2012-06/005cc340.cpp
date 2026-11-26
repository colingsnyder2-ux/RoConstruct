// from server: 100% by Xemicl
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <set>
namespace RBX { class Script; }
typedef std::set<RBX::Script*> ScriptSet;
struct Holder : ScriptSet {
    size_t doErase(RBX::Script* const& k) { return erase(k); }
};
size_t __fastcall wrapper(Holder* h, int, RBX::Script* const& k) { return h->doErase(k); }
