// from server: 100% by king_originala
struct DataSource {
    const void* get();
};

struct S {
    char reserved0[0x10];
    S* source;
    S* parent;
    char reserved1[0x1C];
    DataSource* dataSource;
    char localData[0x58];
    unsigned int version;

    const void* get();
};

struct RevoluteLink {
    virtual void update(void*);
    S* source;
    char reserved[0x90];
    char localData[0x30];
    unsigned int version;

    const void* get();
};

const void* RevoluteLink::get()
{
    S* parent = source->parent;
    parent->get();
    unsigned int currentVersion = parent->version;
    if (version != currentVersion) {
        update(localData);
        version = currentVersion;
    }
    return localData;
}
