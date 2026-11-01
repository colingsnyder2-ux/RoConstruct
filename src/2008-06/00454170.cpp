// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Counted {
    virtual ~Counted();
    virtual void dispose();
    virtual void destroy();
    long use;
    long weak;
    void release();
};

inline void Counted::release()
{
    if (_InterlockedDecrement(&use) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Info {
    char padding[0x1b4];
    int enabled;
};

struct Object {
    Info* getInfo();
};

struct ProviderShared {
    Object* pointer;
    Counted* count;
    ~ProviderShared();
};

inline ProviderShared::~ProviderShared()
{
    if (count)
        count->release();
}

struct Shared {
    Object* pointer;
    Counted* count;
    Shared(const ProviderShared&);
    Shared(const Shared&);
    ~Shared();
    Object* getPointer() const;
};

inline Shared::Shared(const ProviderShared& other)
    : pointer(other.pointer), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->use);
}

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->use);
}

inline Shared::~Shared()
{
    if (count)
        count->release();
}

inline Object* Shared::getPointer() const
{
    return pointer;
}

struct Provider {
    ProviderShared get();
};

struct Guard {
    char storage[12];
    Guard(Shared);
    ~Guard();
};

struct Command {
    virtual void enable(int);
};

void* __cdecl query(Object*);

struct CRobloxDoc {
    char padding[0x94];
    Provider* provider;
    Shared get();
    void update(Command*);
};

void CRobloxDoc::update(Command* command)
{
    Guard guard(provider->get());
    int enabled = get().pointer->getInfo()->enabled;
    bool blocked = query(get().getPointer()) != 0;
    command->enable(enabled && !blocked ? 1 : 0);
}
