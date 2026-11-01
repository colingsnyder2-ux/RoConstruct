// from server: 100% by colin
extern "C" void __cdecl release(void*);
extern "C" void __cdecl deallocate(void*);

struct Storage
{
    void* allocation;
    unsigned char reserved0[8];
    void* begin;
    void* end;
    void* capacity;
    unsigned char reserved1[4];
    void* owner;

    ~Storage();
};

__forceinline Storage::~Storage()
{
    release(owner);
    if (begin)
        deallocate(begin);
    begin = 0;
    end = 0;
    capacity = 0;
    deallocate(allocation);
}

struct S
{
    virtual ~S();
    Storage storage;

    void disconnect();
};

S::~S()
{
    disconnect();
}
