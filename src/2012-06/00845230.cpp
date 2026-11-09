// from server: 66% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_833810(void*, int, void*);

struct SlotWrapper {
    void* get();
};

void* SlotWrapper::get()
{
    void* p = sub_833810(*(void**)0xde1404, 1, *(void**)((char*)this + 4));
    void* q = *(void**)((char*)p + 8);
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
            void* vt = *(void**)q;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 8);
            fn(q);
        }
    }
    return 0;
}
