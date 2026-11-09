// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void helper_006ba160(void*, void*, void*, int);

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

void func_006b9720(void* a, void* b, int c, int d, int e, int f)
{
    RefCounted* p = *(RefCounted**)a;
    void* local = 0;
    helper_006ba160((char*)p + 8, &local, b, 0);
    RefCounted* q = (RefCounted*)local;
    if (q) {
        if (_InterlockedExchangeAdd(&q->refcount, -1) == 1) {
            void** vt = q->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(q);
            if (_InterlockedExchangeAdd(&q->weakrefcount, -1) == 1) {
                void** vt2 = q->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(q);
            }
        }
    }
}
