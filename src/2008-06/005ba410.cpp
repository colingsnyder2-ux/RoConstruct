// from server: 100% by king_originala
typedef void (__thiscall *StringDestructor)(void *);
extern StringDestructor destroyString;

extern "C" void * __stdcall resolveHandle(void *);
void __cdecl releaseHandle(void *);

struct StringStorage {
    unsigned char storage[28];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroyString(this);
}

struct SoundChannel {
    void *handle;
    unsigned char padding[8];
    StringStorage name;

    ~SoundChannel();
};

SoundChannel::~SoundChannel()
{
    if (handle) {
        releaseHandle(resolveHandle(handle));
        handle = 0;
    }
}
