// from server: 100% by EspClaude
// roc 2007-08 0055eeb0  RBX::ClearBackpack::isEnabled (2008-06 0057df80 with 2007 offsets)
struct Entry {
    void* value;
    void* owner;
};

#include <vector>
typedef std::vector<Entry> Children;

struct Backpack {
    char padding[0xc0];
    Children* children;
};

struct Service {
    Backpack* getBackpack();
};

extern "C" Service* findService(void*);

struct ClearBackpack {
    char padding[12];
    void* context;
    bool enabled();
};

bool ClearBackpack::enabled()
{
    Service* service = findService(context);
    if (service) {
        Backpack* backpack = service->getBackpack();
        if (backpack) {
            Children* children = backpack->children;
            unsigned int count = children
                ? children->size()
                : 0;
            return 0U < count;
        }
    }
    return false;
}
