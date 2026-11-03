// from server: 100% by EspClaude
// roc 2007-08 00561fd0  RBX::ClearStarterpack::isEnabled (starter pack has children)
#include <vector>
struct Entry {
    void* value;
    void* owner;
};
typedef std::vector<Entry> Children;

struct StarterPack {
    char padding[0xc0];
    Children* children;
};

struct DataModel {
    StarterPack* getStarterPack();
};

struct ClearStarterpack {
    char padding[12];
    DataModel* dataModel;
    bool enabled();
};

bool ClearStarterpack::enabled()
{
    if (dataModel) {
        StarterPack* pack = dataModel->getStarterPack();
        if (pack) {
            Children* children = pack->children;
            unsigned int count = children
                ? children->size()
                : 0;
            return 0U < count;
        }
    }
    return false;
}
