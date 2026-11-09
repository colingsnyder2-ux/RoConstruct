// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl free(void*);
extern "C" void __cdecl sub_54fd20();

struct Inner
{
    virtual void v0();
};

struct Obj
{
    Inner* ptr;
};

struct S
{
    Obj* field0;
    void method();
};

void S::method()
{
    sub_54fd20();
    Inner* p = this->field0->ptr;
    if (p != 0)
    {
        char* base = (char*)p + 5;
        char* c;
        if (base != 0)
            c = base - 5;
        else
            c = 0;
        char* esi = c - 8;
        if (_InterlockedExchangeAdd((volatile long*)esi, -1) == 1)
        {
            void** vt = *(void***)c;
            void (*fn)(void*) = (void (*)(void*))vt[0];
            fn(0);
            if (_InterlockedExchangeAdd((volatile long*)(esi + 4), -1) == 1)
            {
                free(esi);
            }
        }
    }
}
