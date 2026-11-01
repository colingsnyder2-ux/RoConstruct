// from server: 100% by king_originala
struct CriticalSection
{
    unsigned char storage[24];
    unsigned char initialized;

    void Lock();
    ~CriticalSection();
};

struct Module
{
    virtual long Slot0() = 0;
    virtual long Slot1() = 0;
    virtual long Unlock() = 0;
};

extern Module* module;

struct Factory
{
    virtual long QueryInterface(const void*, void**) = 0;
    virtual unsigned long AddRef() = 0;
    virtual unsigned long Release() = 0;
    virtual long CreateInstance(void*, const void*, void**) = 0;
    virtual long LockServer(int) = 0;

    long references;
    CriticalSection criticalSection;

    ~Factory();
};

Factory::~Factory()
{
    references = (long)0xC0000001UL;
    criticalSection.Lock();
    module->Unlock();
}
