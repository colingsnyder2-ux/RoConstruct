// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __cdecl _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Control {
    long reserved;
    volatile long references;
};

struct Shared {
    void* object;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control) {
        volatile long* count = &control->references;
        _ReadWriteBarrier();
        _InterlockedExchangeAdd(count, 1);
    }
}

struct Guard {
    unsigned char storage[12];

    Guard(Shared);
    ~Guard();
};

struct Text;
struct Result;

extern const char* (__thiscall *text_c_str)(const Text*);
extern void (__thiscall *result_construct)(Result*, const char*);

struct Text {
    const char* c_str() const;
};

inline const char* Text::c_str() const
{
    return text_c_str(this);
}

struct Result {
    void* value;

    Result(const char*);
    ~Result();
};

inline Result::Result(const char* text)
{
    result_construct(this, text);
}

struct Owner {
    unsigned char padding[0x110];
    Text text;
};

struct S {
    unsigned char padding[0x7c];
    Shared shared;
    Owner* owner;

    Result f(void*);
};

Result S::f(void*)
{
    Guard guard(shared);
    return Result(owner->text.c_str());
}
