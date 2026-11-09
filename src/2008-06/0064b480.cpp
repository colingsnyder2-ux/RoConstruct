// from server: 71% by king_originala
extern "C" void __cdecl free(void *);

struct Object {
    virtual ~Object();
};

struct Owner {
    Object *p;
    ~Owner();
};

struct Buffer {
    void *proxy;
    void *reserved0;
    void *reserved1;
    void *first;
    void *last;
    void *limit;
    ~Buffer();
};

struct SleepStage {
    char pad0[8];
    Owner owner;
    char pad0c[4];
    Buffer b10;
    Buffer b28;
    Buffer b40;
    Buffer b58;
    Buffer b70;
    Buffer b88;
    Buffer ba0;
    ~SleepStage();
};

__forceinline Owner::~Owner()
{
    if (p != 0)
        delete p;
}

__forceinline Buffer::~Buffer()
{
    if (first != 0)
        free(first);
    first = 0;
    last = 0;
    limit = 0;
    free(proxy);
}

SleepStage::~SleepStage()
{
}
