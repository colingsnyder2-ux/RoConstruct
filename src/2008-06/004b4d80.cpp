// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct RefCount
{
    long reserved;
    volatile long count;

    void addRef();
};

inline void RefCount::addRef()
{
    _InterlockedIncrement(&count);
}

struct Argument
{
    long a;
    long b;
    long c;
    void* object;
    RefCount* control;
    long padding;

    Argument(const Argument&);
    ~Argument();
};

inline Argument::Argument(const Argument& other)
    : a(other.a), b(other.b), c(other.c),
      object(other.object), control(other.control)
{
    if (control)
        control->addRef();
}

struct Holder
{
    char storage[40];
    Holder();
};

struct Count
{
    RefCount* control;

    Count();
    ~Count();
};

inline Count::Count() : control(0)
{
}

struct Base
{
    void* object;
    Count control;

    Base();
    void reset(Holder*);
};

inline Base::Base() : object(0), control()
{
}

struct Member
{
    char storage[24];
    Member(Argument, int);
    ~Member();
};

struct S : Base
{
    Member member;

    S(const Argument&);
    void finish();
};

S::S(const Argument& argument)
    : member(argument, 0)
{
    reset(new Holder);
    finish();
}
