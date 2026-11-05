// from server: 58% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Tool {
    void assign(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h);
};

void Tool::assign(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h)
{
    if (h) {
        *(void**)h = a;
        *(void**)((char*)h + 4) = b;
        *(void**)((char*)h + 8) = c;
        *(void**)((char*)h + 12) = d;
        *(void**)((char*)h + 16) = e;
        if (c) {
            _InterlockedExchangeAdd((volatile long*)((char*)c + 8), 1);
        }
    }
    if (e) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)e + 8), -1) == 1) {
            void** vt = *(void***)e;
            void (*fn)(void*) = (void (*)(void*))vt[2];
            fn(e);
        }
    }
}
