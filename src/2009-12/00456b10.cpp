// from server: 1% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Obj402120 {
    void* m_p;
};

struct Inner {
    void* m_p;
};

struct S {
    char pad[0x9c];
    void* m_p9c;
    void f(Obj402120* p);
};

void S::f(Obj402120* p)
{
    char buf[0x40];
    Obj402120 tmp;
    Inner inner;
    RefCounted* rc;
    bool flag;

    tmp.m_p = 0;
    Obj402120* r = &tmp;
    (void)r;
    flag = (*(int*)&tmp != 0);

    rc = (RefCounted*)tmp.m_p;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    if (flag) {
        void* p9c = *(void**)((char*)this + 0x9c);
        (void)p9c;
        inner.m_p = 0;
        (void)inner;
        Obj402120* q = &tmp;
        (void)q;
        void* v = *(void**)&tmp;
        (void)v;
        double d = 0.0;
        sprintf(buf, "%.3gfps", d);
        rc = (RefCounted*)tmp.m_p;
        if (rc) {
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[1])(rc);
                if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
                }
            }
        }
        void* obj = *(void**)((char*)this + 0x9c);
        (void)obj;
    }
}
