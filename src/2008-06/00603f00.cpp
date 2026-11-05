// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct BaseTag;
struct ImageTag;

template<class T>
struct Pointer {
    T* object;
    Control* control;

    Pointer();
    Pointer(const Pointer&);
    ~Pointer();
};

template<class T>
inline Pointer<T>::Pointer() : object(0), control(0)
{
}

template<class T>
inline Pointer<T>::Pointer(const Pointer& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

template<class T>
inline Pointer<T>::~Pointer()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

typedef Pointer<BaseTag> BasePointer;
typedef Pointer<ImageTag> ImagePointer;

struct Source {
    BasePointer get();
};

ImagePointer __cdecl convert(const BasePointer&);

ImagePointer __cdecl makeImagePointer(Source* source)
{
    return source ? convert(source->get()) : ImagePointer();
}
