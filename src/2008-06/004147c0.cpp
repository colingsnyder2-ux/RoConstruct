// from server: 100% by king_originala
extern "C" void __cdecl releaseMemory(void*) throw();

struct Storage {
    void* allocation;
    char reserved[28];

    void clear() throw();
    ~Storage();
};

struct Tail {
    ~Tail();
};

struct CopyVerb {
    char reserved[8];
    Storage storage;
    Tail tail;

    ~CopyVerb();
};

inline Storage::~Storage()
{
    clear();
    releaseMemory(allocation);
}

CopyVerb::~CopyVerb()
{
}
