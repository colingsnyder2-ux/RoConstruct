// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct A;
struct B;

template<class T>
struct Shared
{
    T* object;
    Control* control;

    Shared(const Shared& other);
    template<class U> Shared(Shared<U> other);
    ~Shared();
};

template<class T>
__forceinline Shared<T>::Shared(const Shared<T>& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

template<class T>
__forceinline Shared<T>::~Shared()
{
    if (control)
        control->release();
}

struct Result
{
    int first;
    int second;
    Shared<B> value;

    Result(int a, int b, const Shared<B>& p);
};

__forceinline Result::Result(int a, int b, const Shared<B>& p)
    : first(a), second(b), value(p)
{
}

Result __cdecl reconstruct(int a, int b, Shared<A> p)
{
    return Result(a, b, Shared<B>(p));
}
