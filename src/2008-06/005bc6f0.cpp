// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct RefCount
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;
};

struct Asset
{
    unsigned int prefix;
    union
    {
        char text[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct SharedAsset
{
    Asset* asset;
    RefCount* count;

    ~SharedAsset();
};

inline SharedAsset::~SharedAsset()
{
    if (count)
    {
        RefCount* p = count;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Key
{
    char data[32];
};

namespace RBX
{
    class Instance;
    class ServiceProvider
    {
    public:
        SharedAsset fetch(const Key&);
    };
}

RBX::ServiceProvider* __cdecl func_00465210(RBX::Instance*);

struct Settings
{
    char padding[0x139];
    unsigned char enabled;
};

Settings* __cdecl getSettings();

struct CreateInfo
{
    unsigned int size;
    unsigned int length;
    char remaining[100];
};

extern "C" void* __cdecl clearMemory(void*, int, unsigned int);
extern "C" int __stdcall createSound(void*, const char*, unsigned int,
                                    CreateInfo*, void*);
void __cdecl checkResult(int);

struct SoundService
{
    void* sound;
    void* system;
    unsigned int unknown;
    Key key;
    unsigned char enabled;

    void* load(RBX::Instance*);
};

void* SoundService::load(RBX::Instance* instance)
{
    if (!sound)
    {
        SharedAsset asset = func_00465210(instance)->fetch(key);
        if (!asset.asset)
            return 0;

        unsigned int flags = enabled ? 0x10 : 0;
        flags |= (getSettings()->enabled ? 0x40 : 0x20) | 0x800;

        CreateInfo info;
        clearMemory(&info, 0, 108);
        info.size = 108;
        info.length = asset.asset->length;

        const char* data;
        if (asset.asset->capacity >= 16)
            data = asset.asset->storage.pointer;
        else
            data = asset.asset->storage.text;

        checkResult(createSound(system, data, flags, &info, this));
    }
    return sound;
}
