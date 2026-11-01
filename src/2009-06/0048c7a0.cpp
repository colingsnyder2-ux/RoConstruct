// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD
#include <string>
#include <memory>
namespace Ogre {
struct Entry {
    std::string a;
    int x;
    std::string b;
    int y[5];
};
}
template void std::_Destroy_range<std::allocator<Ogre::Entry> >(Ogre::Entry*, Ogre::Entry*, std::allocator<Ogre::Entry>&);
