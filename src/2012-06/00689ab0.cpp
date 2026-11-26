// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <vector>
namespace Ogre { struct MeshLodUsage { char data[0x60]; }; }
struct Holder : std::vector<Ogre::MeshLodUsage> {
    void add(const Ogre::MeshLodUsage& v) { push_back(v); }
};
void __fastcall wrapper(Holder* h, int, const Ogre::MeshLodUsage& v) { h->add(v); }
