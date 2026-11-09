// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Count {
    Control* control;
    ~Count();
    Count& operator=(const Count&);
};

inline Count::~Count()
{
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Pair {
    void* object;
    Count count;
    Pair& operator=(const Pair&);
};

inline Pair& Pair::operator=(const Pair& other)
{
    object = other.object;
    count = other.count;
    return *this;
}

Pair __cdecl makePair(void*);

struct S {
    char padding[0x1c];
    Pair pair;
    void* selected;
    float position[3];

    void* find(void*, void**, float*);
    void f(void*);
};

void S::f(void* input)
{
    selected = find(input, &input, position);
    pair = makePair(selected ? input : 0);
}
