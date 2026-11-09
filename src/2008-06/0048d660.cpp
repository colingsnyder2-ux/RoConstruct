// from server: 43% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    Shared();
    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared()
{
}

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);
}

inline Shared::~Shared()
{
    if (control && _InterlockedExchangeAdd(&control->strong, -1) == 1) {
        control->dispose();
        if (_InterlockedExchangeAdd(&control->weak, -1) == 1)
            control->destroy();
    }
}

struct Range {
    void* data;
    unsigned padding[2];
    unsigned first;
    unsigned last;
};

struct Function {
    void* descriptor;
    Shared value;
};

struct Iterator {
    void* data;
    unsigned position;
};

struct S {
    void apply(Shared value, Range* range);
};

extern void __cdecl callback();
extern void __cdecl construct(S*, void (__cdecl*)(), Shared, Function*);
extern Function __cdecl traverse(Iterator, Iterator, Function);

void S::apply(Shared value, Range* range)
{
    Function function;
    construct(this, callback, value, &function);

    unsigned last = range->last;
    if (range->first > last)
        _invalid_parameter_noinfo();
    void* endData = range->data;

    unsigned first = range->first;
    if (first > range->last)
        _invalid_parameter_noinfo();

    Iterator begin = { range->data, first };
    Iterator end = { endData, last };
    traverse(begin, end, function);
}
