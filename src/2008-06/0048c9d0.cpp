// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared
{
    void* pointer;
    Control* control;

    ~Shared();
};

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Tag
{
    char value;
};

struct Arguments
{
    int* key;
    Shared* value;
};

struct Tree
{
    void __thiscall insert(Tag, void*, Arguments*, int);
};

void __cdecl function(void* object, int key, Shared value)
{
    Tag tag = { 0 };
    Arguments arguments;
    arguments.key = &key;
    arguments.value = &value;
    reinterpret_cast<Tree*>(static_cast<char*>(object) + 4)
        ->insert(tag, object, &arguments, 0);
}
