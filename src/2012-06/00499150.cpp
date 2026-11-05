// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sub_4990D0(int*);
extern "C" void __cdecl sub_972290(int, const char*);

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Obj {
    void* vptr;
    long refcount;
    long refcount2;
};

struct Result {
    void* ptr;
    void* ptr2;
};

int __stdcall sub_499150(Result* out)
{
    int local = 0;
    if (*(char*)0xE580B3 != 0) {
        if (*(int*)0xE1A900 != 0x29A) {
            int (*fn)(const char*, const char*, int) = *(int(**)(const char*, const char*, int))0xE5809C;
            if (fn != 0) {
                if (fn((const char*)0xB42F90, (const char*)0xB42FA8, 0xCA) != 0) {
                    goto skip;
                }
            }
            sub_972290(*(unsigned char*)0xE580B3, (const char*)0xB432F8);
        }
    }
skip:
    int* p = (int*)sub_4990D0(&local);
    int* ecx = (int*)*p;
    if (ecx != 0) {
        ecx = (int*)((char*)ecx + 0x18);
    } else {
        ecx = 0;
    }
    out->ptr = ecx;
    int* eax = (int*)p[1];
    out->ptr2 = eax;
    if (eax != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)eax + 4), 1);
    }
    int* esi = (int*)local;
    if (esi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void** vt = (void**)*esi;
            void (*f1)(int*) = (void (*)(int*))vt[1];
            f1(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt2 = (void**)*esi;
                void (*f2)(int*) = (void (*)(int*))vt2[2];
                f2(esi);
            }
        }
    }
    return (int)out;
}
