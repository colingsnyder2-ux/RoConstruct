// from server: 100% by king_originala
struct GuardData
{
    int a;
    int b;
    int c;

    GuardData();
    ~GuardData();
    void acquire(void*);
};

__forceinline GuardData::GuardData() : a(0), b(0)
{
}

struct Guard
{
    GuardData data;

    Guard(void*);
    ~Guard();
};

__forceinline Guard::Guard(void* value)
{
    data.c = 0;
    data.acquire(value);
}

__forceinline Guard::~Guard()
{
}

struct Owner
{
    char padding[0x198];
    void* value;
};

struct Prefix
{
    char padding[0x14];
};

struct Base
{
    int value;
};

struct Object : Prefix, Base
{
};

struct Interface
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void invoke(Base*, int) = 0;
};

struct S
{
    char padding[0x128];
    Owner* owner;
    Interface* target;

    void f(Object*, int);
};

void S::f(Object* object, int value)
{
    Guard guard(owner->value);
    target->invoke(object, value);
}
