// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern "C" void* (__cdecl *allocate)(unsigned int);
void __cdecl operator delete(void*);

__forceinline void* __cdecl operator new(unsigned int size)
{
    return allocate(size);
}

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Tag {
    char value;
    Tag();
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

struct Item {
    char storage[0x180];
    Item(const Shared&, int);
};

struct Result {
    Item* pointer;
    Control* control;
    Result(Item*, Tag);
    ~Result();
};

__forceinline Tag::Tag() : value(0)
{
}

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

__forceinline Result::~Result()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Result __cdecl build(Shared source, int value)
{
    Tag tag;
    return Result(new Item(source, value), tag);
}
