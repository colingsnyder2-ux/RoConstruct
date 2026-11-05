// from server: 44% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void** vptr;
    volatile long m_ref1;
    volatile long m_ref2;
};

struct StatsItem {
    char pad[0x2001c];
    char m_str[0x14];
    int m_strLen;
};

struct S {
    void* getValue(int arg);
};

struct Str {
    char pad[0x1c];
    Str(const char*);
    ~Str();
};

extern "C" void* __stdcall sub_5973A0(void* out, void* in);
extern "C" void __stdcall sub_77E698(void*);
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" void __cdecl sub_541630(void*);

void* S::getValue(int arg) {
    void* local18[6];

    sub_5973A0(local18, (void*)arg);
    Inner* inner = (Inner*)local18[1];
    void* obj = local18[0];

    if (inner) {
        _InterlockedExchangeAdd(&inner->m_ref1, 1);
    }

    if (inner) {
        if (_InterlockedExchangeAdd(&inner->m_ref1, -1) == 1) {
            void** vt = inner->vptr;
            void (*fn)(Inner*) = (void (*)(Inner*))vt[1];
            fn(inner);
            if (_InterlockedExchangeAdd(&inner->m_ref2, -1) == 1) {
                void** vt2 = inner->vptr;
                void (*fn2)(Inner*) = (void (*)(Inner*))vt2[2];
                fn2(inner);
            }
        }
    }

    StatsItem* item = (StatsItem*)arg;
    char* strPtr;
    if (item->m_strLen < 0x10) {
        strPtr = item->m_str;
    } else {
        strPtr = *(char**)(item->m_str);
    }

    Str str(strPtr);

    void** vt = *(void***)obj;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vt[2];
    fn(obj, local18);

    str.~Str();

    sub_541630(obj);

    if (inner) {
        if (_InterlockedExchangeAdd(&inner->m_ref1, -1) == 1) {
            void** vt2 = inner->vptr;
            void (*fn2)(Inner*) = (void (*)(Inner*))vt2[1];
            fn2(inner);
            if (_InterlockedExchangeAdd(&inner->m_ref2, -1) == 1) {
                void** vt3 = inner->vptr;
                void (*fn3)(Inner*) = (void (*)(Inner*))vt3[2];
                fn3(inner);
            }
        }
    }

    return obj;
}
