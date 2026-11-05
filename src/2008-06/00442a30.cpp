// from server: 100% by king_originala
extern "C" void __cdecl releaseMemory(void *) throw();

struct Base {
    virtual ~Base();
    char storage[0x184];
};

struct Interface {
    virtual void method();
};

struct Sync {
    char storage[0x10];
    ~Sync();
};

struct Memory {
    void *buffer;
    char storage[8];
    void *first;
    void *last;
    void *limit;
    ~Memory();
};

struct AggregateA {
    char storage[0x20];
    ~AggregateA();
};

struct AggregateB {
    char storage[0x24];
    ~AggregateB();
};

struct Sleep {
    char storage[0x20];
    ~Sleep();
};

struct Selection {
    ~Selection();
};

struct CDataModelPropGrid : Base, Interface {
    Sync sync;
    Memory memory;
    AggregateA aggregateA;
    AggregateB aggregateB;
    Sleep sleep;
    Selection selection;

    virtual void method();
    virtual ~CDataModelPropGrid();
};

__forceinline Memory::~Memory()
{
    if (first)
        releaseMemory(first);
    first = 0;
    last = 0;
    limit = 0;
    releaseMemory(buffer);
}

CDataModelPropGrid::~CDataModelPropGrid()
{
}
