// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl free(void*);

struct Inner {
    virtual void f(int);
    char pad[4];
    long ref;
};

struct Outer {
    Inner* m_ptr;
    void release();
};

void Outer::release()
{
    Inner* p = m_ptr;
    if (p) {
        char* base = (char*)p + 5;
        char* obj;
        if (base)
            obj = base - 5;
        else
            obj = 0;
        char* cnt = obj - 8;
        if (_InterlockedExchangeAdd((volatile long*)cnt, -1) == 1) {
            void** vt = *(void***)obj;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(obj, 0);
            char* cnt2 = cnt + 4;
            if (_InterlockedExchangeAdd((volatile long*)cnt2, -1) == 1) {
                free(cnt);
            }
        }
    }
}
