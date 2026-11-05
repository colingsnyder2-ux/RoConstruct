// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control
{
    long reserved;
    volatile long references;

    void addReference();
};

inline void Control::addReference()
{
    volatile long *counter = &references;
    _InterlockedExchangeAdd(counter, 1);
}

struct Shared
{
    void *pointer;
    Control *control;

    Shared(const Shared &);
    ~Shared();
};

inline Shared::Shared(const Shared &other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        control->addReference();
}

struct Element
{
    char data[0x4c];

    Element(const Element &);
    ~Element();
};

struct Elements
{
    Element values[8];
};

struct S
{
    Shared shared;
    int value;
    double number;
    int first;
    int second;
    Elements elements;

    S(const S &);
};

S::S(const S &other)
    : shared(other.shared),
      value(other.value),
      number(other.number),
      first(other.first),
      second(other.second),
      elements(other.elements)
{
}
