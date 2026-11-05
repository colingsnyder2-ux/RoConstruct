// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall CloseHandle(void*);
extern "C" void __cdecl free(void*);

struct Inner {
    void Release();
};

struct Ref {
    long ref;
    char pad[4];
    long count;
};

struct ContentProvider {
    char pad0[4];
    Ref* m4;
    char pad8[4];
    void* mC;
    Inner* m10;
    void Destroy();
};

void ContentProvider::Destroy()
{
    Inner* p = m10;
    if (p) {
        p->Release();
        free(p);
    }
    void* q = mC;
    mC = 0;
    if (q) {
        CloseHandle(q);
    }
    Ref* r = m4;
    if (r) {
        if (_InterlockedExchangeAdd(&r->count, -1) == 1) {
            (*(void (__stdcall**)(Ref*))r)(r);
        }
    }
}
