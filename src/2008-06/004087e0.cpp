// from server: 100% by king_originala
struct Interface
{
    virtual int __stdcall Query(void*, void**) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct ReleaseHolder
{
    Interface* pointer;
    ~ReleaseHolder();
};

inline ReleaseHolder::~ReleaseHolder()
{
    if (pointer)
        pointer->Release();
}

struct Module
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void Unlock() = 0;
};

extern Module* module;

struct S
{
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();

    unsigned long references;
    unsigned char reserved[16];
    ReleaseHolder holder;

    ~S();
};

S::~S()
{
    references = 0xC0000001UL;
    module->Unlock();
}
