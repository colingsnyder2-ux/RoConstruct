// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct RefCounted
{
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Obj450ec0
{
    char pad[0x14c];
    int field14c;
};

struct Obj1e0
{
    char pad[0x40];
    double field40;
};

struct Inner
{
    void* vptr;
    RefCounted* ptr;
};

struct Outer
{
    char pad[0x78];
    void* field78;
};

struct S
{
    void* field0;
    RefCounted* field4;
};

extern void* g_403800;
extern void* g_403830;
extern void* g_40d550;
extern void* g_450ec0;
extern void* g_5595a0;
extern void* g_77e968;
extern char g_785954;
extern char g_7919bc;

struct ReportAbuseVerb
{
    void func(void* arg);
};

void ReportAbuseVerb::func(void* arg)
{
    S s;
    Inner inner;
    char buf[32];
    void* tmp;
    RefCounted* rc;
    int flag;
    int val;

    s.field0 = 0;
    s.field4 = 0;

    ((void (__thiscall*)(void*, void*))&g_403830)(this, &s);
    flag = (s.field0 != 0);

    rc = s.field4;
    if (rc)
    {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
        {
            ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
            {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    if (flag)
    {
        ((void (__thiscall*)(void*, Inner*))&g_403800)(((Outer*)this)->field78, &inner);

        tmp = inner.ptr;
        inner.ptr = 0;
        if (tmp)
        {
            _InterlockedExchangeAdd((volatile long*)((char*)tmp + 4), 1);
        }

        ((void (__thiscall*)(void*))&g_40d550)(&inner);

        rc = inner.ptr;
        if (rc)
        {
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
            {
                ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
                if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
                {
                    ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
                }
            }
        }

        ((void (__thiscall*)(void*, S*))&g_403830)(this, &s);
        val = ((Obj450ec0*)((void* (__thiscall*)(void*))&g_450ec0)(s.field0))->field14c;

        rc = s.field4;
        if (rc)
        {
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
            {
                ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
                if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
                {
                    ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
                }
            }
        }

        if (val == 1)
        {
            ((void (__thiscall*)(void*, S*))&g_403830)(this, &s);
            sprintf(buf, &g_7919bc, ((Obj1e0*)((char*)s.field0 + 0x1e0))->field40);

            rc = s.field4;
            if (rc)
            {
                if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
                {
                    ((void (__thiscall*)(RefCounted*))rc->vptr)(rc);
                    if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1)
                    {
                        ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
                    }
                }
            }

            ((void (__thiscall*)(void*, char*))((void**)arg)[3])(arg, buf);
        }
        else
        {
            ((void (__thiscall*)(void*, char*))((void**)arg)[3])(arg, &g_785954);
        }

        ((void (__thiscall*)(void*))&g_5595a0)(&inner);
    }
}
