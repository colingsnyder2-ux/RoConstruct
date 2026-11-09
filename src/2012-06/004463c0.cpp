// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_426130();

struct IAsyncResult {
    void* vfptr;
    int field_4;
    int field_8;
    void* field_c;
    int field_10;
    void* field_14;
    IAsyncResult* ctor(void* a, int b, void* c);
};

IAsyncResult* IAsyncResult::ctor(void* a, int b, void* c)
{
    this->vfptr = 0;
    this->field_4 = 0;
    this->field_8 = 0;
    this->field_c = a;
    if (a) {
        void** vt = *(void***)a;
        void (*fn)(void*) = (void (*)(void*))vt[1];
        fn(a);
    }
    this->field_10 = b;
    this->field_14 = c;
    if (c) {
        _InterlockedExchangeAdd((volatile long*)((char*)c + 8), 1);
    }
    this->field_8 = sub_426130();
    if (c) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)c + 4), -1) == 1) {
            void** vt = *(void***)c;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1) {
                void** vt2 = *(void***)c;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(c);
            }
        }
    }
    return this;
}
