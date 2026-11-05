// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void* __cdecl sub_57E370(void*, void*, void*, int);
extern "C" void __cdecl sub_41B1A0(void*, void*);
extern "C" void __cdecl sub_854A90(void*, void*, void*);
extern "C" void __cdecl sub_41C010(void*);
extern "C" void __cdecl sub_708980(void*, void*);
extern "C" void __cdecl sub_41B230(void*);
extern "C" void __cdecl sub_41AF50(void*);

extern "C" void* __cdecl sub_B90258();
extern "C" void* __cdecl sub_B7A220();

struct RbxSceneUpdater {
    void* f(void* a, void* b, void* c);
};

void* RbxSceneUpdater::f(void* a, void* b, void* c)
{
    void* esi = 0;
    void* p = sub_7F3860(0x48);
    if (p != 0) {
        esi = sub_57E370(p, b, c, 0x7fffffff);
    }
    char buf1[8];
    sub_41B1A0(buf1, esi);
    sub_854A90(buf1, esi, esi);
    sub_41C010(this);
    sub_708980(this, buf1);
    sub_B90258();
    void* edx = *(void**)buf1;
    void* esi2 = *(void**)(buf1 + 4);
    void* tmp[2];
    tmp[0] = edx;
    tmp[1] = esi2;
    if (esi2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), 1);
    }
    sub_41B230(tmp);
    void* edi = sub_B7A220();
    void* ebp = c;
    *(void**)ebp = *(void**)edi;
    void* eax = *(void**)((char*)edi + 4);
    *(void**)((char*)ebp + 4) = eax;
    if (eax != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)eax + 8), 1);
    }
    sub_41AF50(buf1);
    if (esi2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 4), -1) == 1) {
            void* vt = *(void**)esi2;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 4);
            fn(esi2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi2 + 8), -1) == 1) {
                void* vt2 = *(void**)esi2;
                void (*fn2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                fn2(esi2);
            }
        }
    }
    return ebp;
}
