// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

template<class T> struct Shared {
    T* pointer;
    Control* control;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

template<class T>
inline Shared<T>::Shared() : pointer(0), control(0) {}

template<class T>
inline Shared<T>::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    Control* p = control;
    if (p)
        _InterlockedIncrement(&p->strong);
}

template<class T>
inline Shared<T>::~Shared() {
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

struct Source {
    Shared<Source> get();
};

Shared<void> __cdecl convert(const Shared<Source>&);

Shared<void> __cdecl reconstruct(Source* source) {
    return source ? convert(source->get()) : Shared<void>();
}
