// from server: 32% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall G1_func_0077e69c();
extern "C" void __stdcall G1_func_0077e6ac();

struct S {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    char field14[0x24];
    void func(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l);
};

void S::func(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, void* i, void* j, void* k, void* l)
{
    void* p1 = b;
    void* p2 = d;
    this->field0 = a;
    this->field4 = p1;
    if (p1 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p1 + 4), 1);
    }
    this->field8 = c;
    this->fieldC = p2;
    if (p2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), 1);
    }
    this->field10 = e;
    G1_func_0077e69c();
    if (p1 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p1 + 4), -1) == 1) {
            (*(void (__stdcall**)(void*))((*(char**)p1) + 4))(p1);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p1 + 8), -1) == 1) {
                (*(void (__stdcall**)(void*))((*(char**)p1) + 8))(p1);
            }
        }
    }
    if (p2 != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), -1) == 1) {
            (*(void (__stdcall**)(void*))((*(char**)p2) + 4))(p2);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p2 + 8), -1) == 1) {
                (*(void (__stdcall**)(void*))((*(char**)p2) + 8))(p2);
            }
        }
    }
    G1_func_0077e6ac();
}
