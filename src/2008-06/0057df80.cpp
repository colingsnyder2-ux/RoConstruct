// from server: 100% by king_originala
struct Entry {
    void* value;
    void* owner;
};

struct Children {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Backpack {
    char padding[0x108];
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
                ? children->last - children->first
                : 0;
            return 0U < count;
        }
    }
    return false;
}
