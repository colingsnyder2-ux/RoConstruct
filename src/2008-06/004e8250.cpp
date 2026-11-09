// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct Resource {
    virtual ~Resource();
    volatile long references;
    void release();
};

struct ResourceRef {
    Resource* pointer;
    unsigned long reserved;
    ~ResourceRef();
};

struct ControlBlock {
    virtual ~ControlBlock();
    virtual void dispose();
    virtual void destroy();
    volatile long references;
    volatile long weakReferences;
};

struct SharedRef {
    void* pointer;
    ControlBlock* control;
    ~SharedRef();
};

struct Member {
    unsigned char storage[20];
    ~Member();
};

struct Base {
    virtual ~Base();
    unsigned char storage[84];
};

struct S : Base {
    Member first;
    Member second;
    Member third;
    Member fourth;
    Member fifth;
    SharedRef shared;
    ResourceRef firstResource;
    ResourceRef secondResource;
    virtual ~S();
};

__forceinline ResourceRef::~ResourceRef()
{
    if (pointer) {
        if (InterlockedDecrement(&pointer->references) == 0) {
            pointer->release();
            if (pointer)
                delete pointer;
        }
        pointer = 0;
    }
}

__forceinline SharedRef::~SharedRef()
{
    ControlBlock* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->references) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weakReferences) == 0)
                p->destroy();
        }
    }
}

S::~S()
{
}
