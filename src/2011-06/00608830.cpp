// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_00597d70();
extern "C" void* __cdecl func_00425980(void*);
extern "C" void __cdecl func_00721520();
extern "C" void __cdecl func_00402560();
extern "C" void __cdecl func_005af2c0();
extern "C" void* __cdecl func_0080b2ea();
extern "C" void __cdecl func_00422920();

struct S {
    char pad0[0x90];
    int field_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    int field_a4;
    void f(void* arg);
};

void S::f(void* arg)
{
    func_00597d70();
    if (field_98 != 0)
        return;
    void* p = func_00425980(*(void**)((char*)arg + 8));
    func_00721520();
    int* q = (int*)p;
    int v = *q;
    q++;
    func_00402560();
    field_98 = v;
    int* r = (int*)field_9c;
    if (r != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            void** vt = *(void***)r;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                void** vt2 = *(void***)r;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(r);
            }
        }
    }
    if (field_98 == 0)
        return;
    int* list = (int*)(field_98 + 0x94);
    int* it = (int*)list[1];
    int* end = (int*)list[2];
    if (it == end)
        goto done;
    do {
        void* obj = func_0080b2ea();
        if (obj != 0) {
            int* vec = (int*)((char*)this + 0xa0);
            int* vecEnd = (int*)vec[2];
            int* vecBegin = (int*)vec[1];
            if (vecEnd != vecBegin) {
                int cap = (int)vec[3];
                int sz = ((char*)vecEnd - (char*)vecBegin) >> 2;
                int capSz = (cap - (int)vecBegin) >> 2;
                if ((unsigned)sz < (unsigned)capSz) {
                    *vecEnd = (int)obj;
                    vec[2] = (int)(vecEnd + 1);
                } else {
                    func_00422920();
                }
            } else {
                func_00422920();
            }
        }
        it += 2;
    } while (it != end);
done:
    func_005af2c0();
}
