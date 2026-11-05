// from server: 23% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    void (__thiscall **vptr)(void);
    long refCount;
};

struct MarshaledListener
{
    void (__thiscall **vptr)(void);
    int field_4;
    RefCounted *field_8;
    void *field_c;
    char field_10[8];

    void destroy();
};

void __cdecl sub_437B80(void *, void *);
void __cdecl sub_41DA00(void *);

void MarshaledListener::destroy()
{
    this->vptr = (void (__thiscall **)(void))0x787f94;

    if (this->field_c != 0)
    {
        sub_437B80(this->field_c, this);
    }

    sub_41DA00(&this->field_10[0]);

    RefCounted *p = this->field_8;
    if (p != 0)
    {
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1)
        {
            p->vptr[1]();
            if (_InterlockedExchangeAdd((volatile long *)((char *)p + 8), -1) == 1)
            {
                p->vptr[2]();
            }
        }
    }

    this->vptr = (void (__thiscall **)(void))0x787f68;
}
