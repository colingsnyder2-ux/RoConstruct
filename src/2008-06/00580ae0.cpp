// from server: 100% by king_originala
struct Entry {
    unsigned int first;
    unsigned int second;
};

struct Entries {
    char padding[12];
    Entry* begin;
    Entry* end;
};

struct Object {
    char padding[264];
    Entries* entries;
};

struct Context {
    Object* getObject();
};

struct ClearStarterpack {
    char padding[12];
    Context* context;
    bool check();
};

bool ClearStarterpack::check()
{
    if (context) {
        Object* object = context->getObject();
        if (object) {
            Entries* entries = object->entries;
            unsigned int count = entries
                ? static_cast<unsigned int>(entries->end - entries->begin)
                : 0;
            return count > 0;
        }
    }
    return false;
}
