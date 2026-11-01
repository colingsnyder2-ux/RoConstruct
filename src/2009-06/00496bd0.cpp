// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <hash_map>

namespace Ogre {
class Renderable;
class TwoDManager {
public:
    void remove(Renderable* r);
private:
    char pad[0x48];
    typedef stdext::hash_map<Renderable*, int> Map;
    Map map;
};

void TwoDManager::remove(Renderable* r)
{
    map.erase(map.find(r));
}
}
