// from server: 100% by king_originala
extern "C" void (__thiscall *destroyString)(void *);
extern "C" void __cdecl releaseMemory(void *);

struct OwnedPointer {
    void *value;
    ~OwnedPointer();
};

struct Owner {
    OwnedPointer pointer;
    char reserved[28];
    void cleanup();
    ~Owner();
};

struct Lock {
    void *object;
    bool criticalSection;
    char reserved[7];
    ~Lock();
};

struct String {
    char storage[28];
    ~String();
};

struct CRobloxModule {
    Owner owner;
    Lock lock;
    String string;
    ~CRobloxModule();
};

__forceinline OwnedPointer::~OwnedPointer()
{
    releaseMemory(value);
}

__forceinline Owner::~Owner()
{
    cleanup();
}

__forceinline String::~String()
{
    destroyString(this);
}

CRobloxModule::~CRobloxModule()
{
}
