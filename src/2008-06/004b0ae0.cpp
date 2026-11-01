// from server: 100% by king_originala
extern "C" void* __cdecl allocate(unsigned int);

struct Storage {
    void* data;
    Storage(unsigned int);
    ~Storage();
};

__forceinline Storage::Storage(unsigned int size)
    : data(allocate(size))
{
}

struct Link {
    void* data;
    unsigned int reserved;
    void initialize(void***, void*, void*);
};

struct State {
    unsigned int prefix[2];
    Link link;
    unsigned int reserved[2];
    float scale;
    unsigned int extra;
    void* current;

    State();
    void finish();
};

struct Item {
    unsigned int prefix;
    Storage storage;
    unsigned int reserved;
    State state;
    unsigned int tail;

    Item(void**, unsigned int);
};

Item::Item(void** argument, unsigned int)
    : storage(0x298), state()
{
    State* s = &state;
    Item* owner = s ? reinterpret_cast<Item*>(
        reinterpret_cast<char*>(s) - 12) : 0;
    void* buffer = owner->storage.data;
    void* end = buffer ? reinterpret_cast<char*>(buffer) + 0x290 : 0;

    s->link.initialize(&argument, end, *argument);
    s->scale = 1.0f;
    s->current = s->link.data;
    s->finish();
    tail = 0;
}
