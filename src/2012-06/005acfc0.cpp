// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    double value;
    unsigned char state;
};

void __stdcall f(S *a, const S *b, double c);

struct Inner
{
    void* p;
};

struct Obj
{
    char pad0[0x220];
    Inner inner;
    char pad1[4];
    float f228;
};

struct Ref
{
    void* p;
};

struct RefHolder
{
    Ref* ptr;
};

struct Base
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Counted
{
    long ref1;
    long ref2;
};

extern "C" void __stdcall sub_586260();
extern "C" void __stdcall sub_439330();
extern "C" void __stdcall sub_6dde00();
extern "C" void __stdcall sub_9779e0(S* a, const S* b, double c);

struct TouchJob
{
    bool check();
    S* run(S* out, void* a, void* b);
};

bool TouchJob::check()
{
    return true;
}

S* TouchJob::run(S* out, void* a, void* b)
{
    Obj* self = (Obj*)this;
    if (!check())
    {
        out->value = 0.0;
        out->state = 0;
        return out;
    }

    RefHolder h;
    sub_439330();

    Ref* r = h.ptr;
    if (r != 0 && *(unsigned long*)((char*)r + 0x38) > 0)
    {
        double d = (double)self->f228;
        sub_9779e0(out, (const S*)a, d);
        sub_6dde00();
        return out;
    }

    Counted* c = (Counted*)h.ptr;
    if (c != 0)
    {
        if (_InterlockedExchangeAdd(&c->ref1, -1) == 1)
        {
            Base* bp = (Base*)c;
            bp->v1();
            if (_InterlockedExchangeAdd(&c->ref2, -1) == 1)
            {
                bp->v2();
            }
        }
    }

    out->value = 0.0;
    out->state = 0;
    return out;
}
