// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
#include <string>
#include <algorithm>
namespace Ogre {
class Archive;
struct FileInfo {
    Archive* archive;
    std::string filename;
    std::string path;
    char rest[0x14];
};
}
namespace std {
template Ogre::FileInfo* _Copy_opt<Ogre::FileInfo*, Ogre::FileInfo*>(Ogre::FileInfo*, Ogre::FileInfo*, Ogre::FileInfo*, random_access_iterator_tag, _Nonscalar_ptr_iterator_tag, _Range_checked_iterator_tag);
}
