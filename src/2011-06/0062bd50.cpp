// from server: 77% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_763C20(int, int, int);
extern "C" void __cdecl sub_80A058(void*);

struct WeakFunctionRef {
    void* ptr;
    void Release();
};

void WeakFunctionRef::Release()
{
    void* p = this->ptr;
    if (p == 0)
        return;
    if (_InterlockedExchangeAdd((volatile long*)p, -1) != 1)
        return;
    if (p == 0)
        return;
    sub_763C20(*(int*)((char*)p + 4), -10000, *(int*)((char*)p + 8));
    sub_80A058(p);
}
