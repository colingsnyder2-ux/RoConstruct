// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Count {
    virtual ~Count();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Prefix { char storage[20]; };
struct Context { int storage; };
struct Source : Prefix, Context {};

template<class T> struct Shared {
    T* pointer;
    Count* count;

    template<class U> Shared(const Shared<U>& other);
    ~Shared();
};

template<class T>
template<class U>
__forceinline Shared<T>::Shared(const Shared<U>& other)
    : pointer(other.pointer), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->strong);
}

template<class T>
__forceinline Shared<T>::~Shared()
{
    Count* c = count;
    if (c && _InterlockedDecrement(&c->strong) == 0) {
        c->dispose();
        if (_InterlockedDecrement(&c->weak) == 0)
            c->destroy();
    }
}

struct Channel {
    void activate();
};

namespace RBX {
    class Instance;
    class ServiceProvider;
}

extern Channel* __stdcall findChannel(int, const char*);
extern void __cdecl prepare(void*, int);
extern void __cdecl selectValue(void*, int);
extern RBX::Instance* __cdecl readInstance(void*, int);
extern void __cdecl removeValue(void*, int);
extern RBX::ServiceProvider* __cdecl func_005aecd0(RBX::Instance*);
extern Shared<Source> __cdecl obtainContext(RBX::ServiceProvider*);
extern void __cdecl publishContext(void*, Shared<Context>);

int __cdecl reconstructed(void* state)
{
    findChannel(1, "Stats")->activate();
    prepare(state, 67);
    selectValue(state, -10002);
    RBX::Instance* instance = readInstance(state, -1);
    removeValue(state, -2);
    publishContext(state, obtainContext(func_005aecd0(instance)));
    return 1;
}
