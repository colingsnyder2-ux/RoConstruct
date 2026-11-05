// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Control
{
    virtual void slot0();
    virtual void slot1();
    virtual void release();
    long spare;
    volatile long references;

    void addRef();
    void releaseRef();
};

inline void Control::addRef()
{
    _InterlockedIncrement(&references);
}

inline void Control::releaseRef()
{
    if (_InterlockedDecrement(&references) == 0)
        release();
}

struct Count
{
    Control* pointer;

    Count(const Count& other);
    ~Count();
};

inline Count::Count(const Count& other) : pointer(other.pointer)
{
    if (pointer)
        pointer->addRef();
}

inline Count::~Count()
{
    if (pointer)
        pointer->releaseRef();
}

struct Shared
{
    void* object;
    Count control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
}

inline Shared::~Shared()
{
}

struct Iterator
{
    void* owner;
    unsigned int offset;

    const Shared& get();
};

extern void __cdecl consume(Shared value);

struct Source
{
    unsigned long get();
};

struct DebrisService
{
    unsigned char padding0[0x130];
    void* owner;
    unsigned char padding1[12];
    Shared** map;
    unsigned int mapSize;
    unsigned int offset;
    int count;
    unsigned long spare;
    unsigned long result;

    void clear(void* unused, Source* source);
};

void DebrisService::clear(void* unused, Source* source)
{
    while (count > 0)
    {
        unsigned int position = offset;
        if (position > position + count)
            _invalid_parameter_noinfo();

        Iterator iterator;
        iterator.owner = owner;
        iterator.offset = position;
        consume(iterator.get());

        if (count != 0)
        {
            map[offset >> 1][offset & 1].~Shared();

            ++offset;
            if (mapSize * 2 <= offset)
                offset = 0;

            if (--count == 0)
                offset = 0;
        }
    }

    result = source ? source->get() : 0;
}
