// from server: 50% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma optimize("y", off)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long use_count;
    volatile long weak_count;
};

struct Result {
    void verify(int);
};

struct Object {
    Result* getResult();
};

struct Shared {
    Object* object;
    Control* control;
    __forceinline ~Shared();
};

struct Provider {
    Shared get();
};

struct Resource {
    unsigned char storage[20];
    ~Resource();
};

struct Stream {
    unsigned char storage[140];
    ~Stream();
};

struct CRobloxDoc {
    unsigned char storage[148];
    Provider* provider;
    int f(int);
};

Shared __stdcall acquire();

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedExchangeAdd(&p->use_count, -1) == 0) {
            p->dispose();
            if (_InterlockedExchangeAdd(&p->weak_count, -1) == 0)
                p->destroy();
        }
    }
}

int CRobloxDoc::f(int)
{
    Stream stream;
    Resource resource;
    acquire();
    Result* result = provider->get().object->getResult();
    result->verify(1);
    return 1;
}
