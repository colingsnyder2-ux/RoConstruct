// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

Shared::~Shared()
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

struct Tag {
    int value;

    Tag(int);
    Tag(const Tag&);
};

Tag::Tag(int v) : value(v)
{
}

Tag::Tag(const Tag& other) : value(other.value)
{
}

struct Pair {
    int first;
    int second;

    Pair(int, int);
};

Pair::Pair(int a, int b) : first(a), second(b)
{
}

struct Value {
    Shared object;
    Tag value;

    Value(Shared, Tag);
    Value(const Value&);
};

Value::Value(const Value& other)
    : object(other.object), value(other.value)
{
}

struct Result {
    Pair pair;
    Value value;

    Result(const Pair&, const Value&);
};

Result::Result(const Pair& p, const Value& v)
    : pair(p), value(v)
{
}

Result __cdecl reconstruct(int a, int b, Shared object, int value)
{
    return Result(Pair(a, b), Value(object, value));
}
