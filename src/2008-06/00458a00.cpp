// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// v30: guard in f() per exact sibling 004589c0: if (source) forward(source->get());
// else forward(Result()); get() = sret thiscall (0x403040, ret 4). Both branches share
// one arg-area temp -> mov eax,esp materializes before the EH spill.
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct Control
{
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedExchangeAdd(&strong, -1) == 1)
    {
        dispose();
        if (_InterlockedExchangeAdd(&weak, -1) == 1)
            destroy();
    }
}

struct Result
{
    unsigned int first;
    unsigned int second;

    Result();
    Result(const Result&);
    ~Result();
};

struct Source
{
    Result get();
};

inline Result::Result()
{
    first = 0;
    second = 0;
}

inline Result::Result(const Result& other)
    : first(other.first), second(other.second)
{
    Control* control = reinterpret_cast<Control*>(second);
    if (control)
    {
        volatile long* count = &control->strong;
        _InterlockedIncrement(count);
    }
}

inline Result::~Result()
{
    if (second)
        reinterpret_cast<Control*>(second)->release();
}

extern Result globalResult;

struct Sink
{
    virtual void invoke(Result, Result);
};

struct S
{
    unsigned char padding[0x54];
    Source* source;
    unsigned char padding2[0x37c];
    Sink sink;

    void initialize();
    void forward(Result);
    void f();
};

void S::f()
{
    initialize();
    if (source)
        forward(source->get());
    else
        forward(Result());
    Sink* destination = &sink;
    destination->invoke(globalResult, Result());
}
