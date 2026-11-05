// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct IStepped {
    void* vptr;
    int field_4;
    int field_8;
    void construct(int a, int b, int c, int d);
};

void __stdcall sub_4b4430(int);

void IStepped::construct(int a, int b, int c, int d)
{
    RefCounted* rc = (RefCounted*)b;
    if (rc != 0) {
        _InterlockedExchangeAdd(&rc->refcount, 1);
    }
    sub_4b4430(d);
    this->field_8 = c;
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(RefCounted*))((void**)rc->vptr)[1])(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                ((void (__stdcall*)(RefCounted*))((void**)rc->vptr)[2])(rc);
            }
        }
    }
}
