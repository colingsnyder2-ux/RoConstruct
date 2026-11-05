// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
extern int destroyedCount;
extern int residentBytes;
extern int liveCount;

struct Base {
    virtual void function();
    ~Base();
    char reserved[36];
};

struct Handle {
    ~Handle();
    void* value;
};

struct Storage {
    ~Storage();
    char reserved[136];
};

struct Entry {
    ~Entry();
    char reserved[12];
};

struct Payload {
    ~Payload();
    int size();
    char reserved[4];
};

struct TextureProxy : Base {
    Handle first;
    Handle second;
    Storage storage;
    Handle third;
    char reserved[28];
    Entry entry1;
    Entry entry2;
    Payload payload;

    virtual void function();
    ~TextureProxy();
};

#pragma optimize("", off)
TextureProxy::~TextureProxy()
{
    destroyedCount = destroyedCount + 1;
    liveCount = liveCount - 1;
    residentBytes = residentBytes - payload.size();
}
#pragma optimize("", on)
