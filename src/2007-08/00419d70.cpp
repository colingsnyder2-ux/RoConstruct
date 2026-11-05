// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Helper {
    void* field0;
    void* field4;
};

struct Inner {
    void* field0;
    void* field4;
};

struct Outer {
    char pad[0x28];
    void* field28;
    void* field2c;
    void method(int a, int b, int c, int d);
};

extern "C" void* __cdecl sub_56efb0(void*);
extern "C" void* __cdecl sub_56d6f0();
extern "C" void __cdecl sub_419d20(void*, void*);

void Outer::method(int a, int b, int c, int d)
{
    void* p1 = sub_56efb0((void*)c);
    void* p2 = sub_56efb0((void*)b);
    void* v1 = *(void**)p1;
    void* v2 = *(void**)p2;
    int ecx = (int)field2c + a;
    void* edx = field28;
    void* local;
    void* result = ((void* (__thiscall*)(void*, void*, void*, void*))edx)((void*)ecx, v2, v1, &local);
    void* esi = result;
    void* r = sub_56d6f0();
    *(void**)d = r;
    sub_419d20((void*)(d + 4), esi);
    void* eax = local;
    if (eax) {
        void* esi2 = eax;
        volatile long* cnt = (volatile long*)((char*)eax + 4);
        if (_InterlockedExchangeAdd(cnt, -1) == 1) {
            void** vt = *(void***)esi2;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(esi2);
            volatile long* cnt2 = (volatile long*)((char*)esi2 + 8);
            if (_InterlockedExchangeAdd(cnt2, -1) == 1) {
                void** vt2 = *(void***)esi2;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(esi2);
            }
        }
    }
}
