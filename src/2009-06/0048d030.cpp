// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
#include <string>
#include <vector>
namespace Ogre {
class Archive;
struct FileInfo {
    Archive* archive;
    std::string filename;
    std::string path;
    char rest[0x14];
};
}
template std::vector<Ogre::FileInfo>& std::vector<Ogre::FileInfo>::operator=(const std::vector<Ogre::FileInfo>&);
