// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_425280(void*);
extern "C" void* __cdecl sub_721520(void*, void*);
extern "C" void* __cdecl sub_697580(void*, void*, int);
extern "C" void* __cdecl sub_634110(void*, void*);
extern "C" char __cdecl sub_7F8E00(void*, void*);
extern "C" void __cdecl sub_7F8C90(void*);
extern "C" void __cdecl sub_7F8E90(void*, void*);

struct RefCounted
{
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Tool
{
    char pad0[0x44];
    void* field44;
    char pad48[0x238 - 0x48];
    char field238[4];
    char field23c[4];

    void func();
};

void Tool::func()
{
    if (*(void**)((char*)this + 0x44) == 0)
    {
        sub_7F8C90((char*)this + 0x238);
        sub_7F8C90((char*)this + 0x23c);
        return;
    }

    unsigned char b = *(unsigned char*)0xccc1e9;
    void* tmp;
    sub_721520(&tmp, this);
    void* s = sub_697580(&tmp, (void*)0x630f20, 0);
    void* r = sub_634110((char*)*(void**)((char*)this + 0x44) + 0x74, &tmp);
    if (sub_7F8E00((char*)this + 0x238, r))
    {
        sub_7F8C90((char*)this + 0x238);
        sub_7F8E90((char*)this + 0x238, r);
    }
    if (tmp)
        sub_425280((char*)tmp + 5);
    if (s)
    {
        RefCounted* rc = (RefCounted*)s;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
        {
            ((void (__thiscall*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
                ((void (__thiscall*)(void*))((void**)rc->vptr)[2])(rc);
        }
    }

    b = *(unsigned char*)0xccc1e9;
    sub_721520(&tmp, this);
    s = sub_697580(&tmp, (void*)0x630fa0, 0);
    r = sub_634110((char*)*(void**)((char*)this + 0x44) + 0x78, &tmp);
    if (sub_7F8E00((char*)this + 0x23c, r))
    {
        sub_7F8C90((char*)this + 0x23c);
        sub_7F8E90((char*)this + 0x23c, r);
    }
    if (tmp)
        sub_425280((char*)tmp + 5);
    if (s)
    {
        RefCounted* rc = (RefCounted*)s;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
        {
            ((void (__thiscall*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
                ((void (__thiscall*)(void*))((void**)rc->vptr)[2])(rc);
        }
    }
}
