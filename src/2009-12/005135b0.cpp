// from server: 86% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef void (__thiscall *ReleaseFunction)(void*, int);

extern "C" void* __stdcall GetProcessHeap();
extern "C" int __stdcall HeapFree(void*, int, void*);

struct S_005135b0
{
    void* m_object;
    void f();
};

void S_005135b0::f()
{
    void* object = m_object;
    if (object != 0)
    {
        volatile long* count = (volatile long*)((char*)object + 4);
        if (_InterlockedExchangeAdd(count, -1) == 1)
        {
            void** table = *(void***)object;
            ReleaseFunction release = (ReleaseFunction)table[0];
            release(object, 0);
            HeapFree(GetProcessHeap(), 0, object);
        }
    }
}
