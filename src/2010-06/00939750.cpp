// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct Key {
    void* ptr;
    char pad[8];
};

struct S {
    Key* f(void* a, void* b, void* c, void* d);
};

extern "C" void* __stdcall sub_7A8BEA(void*, void*, void*, void*, void*);
extern "C" void* __stdcall sub_936DE0();
extern "C" void* __stdcall sub_938820();
extern "C" void* __stdcall sub_939000();
extern "C" void __stdcall sub_402090(void*);

Key* S::f(void* a, void* b, void* c, void* d)
{
    Key* result = (Key*)a;
    result->ptr = 0;
    *(void**)((char*)result + 4) = 0;
    void* esi = b;
    void* local = 0;
    int state = 1;

    if (*(void**)((char*)esi + 0xc) == 0) {
        sub_936DE0();
        state = 1;
    } else {
        void* r = sub_7A8BEA(*(void**)((char*)esi + 8), (void*)0xBB1BDC, (void*)0xB9960C, 0, 0);
        if (r == 0) {
            sub_938820();
            state = 3;
        } else {
            sub_939000();
            state = 2;
        }
        sub_402090((char*)result + 4);
        if (local) {
            RefCounted* rc = (RefCounted*)local;
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
                ((void(__thiscall*)(void*))rc->vptr)(rc);
                if (_InterlockedExchangeAdd(&rc->weakref, -1) == 1) {
                    ((void(__thiscall*)(void*))rc->vptr)(rc);
                }
            }
        }
    }
    return result;
}
