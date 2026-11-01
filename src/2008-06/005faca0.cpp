// from server: 100% by king_originala
namespace G3D {
struct System {
    static void __cdecl alignedFree(void*);
};
}

void __cdecl operator delete(void*);

extern int liveCount;

struct Buffer {
    void* data;
    int size;
    int capacity;
    ~Buffer();
};

struct Owned {
    virtual ~Owned();
};

struct Owner {
    Owned* p;
    ~Owner();
};

struct Storage {
    void* data;
    int size;
    int capacity;
    ~Storage();
};

struct S {
    int reserved4;
    Owner first;
    int reservedC;
    Buffer* buffer;
    Storage storage;
    Owner last;
    virtual ~S();
};

__forceinline Owner::~Owner()
{
    if (p)
        delete p;
}

__forceinline Storage::~Storage()
{
    G3D::System::alignedFree(data);
    data = 0;
    size = 0;
    capacity = 0;
}

S::~S()
{
    --liveCount;
    if (buffer)
        delete buffer;
}
