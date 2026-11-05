// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* p0;
    void* p4;
    void* p8;
    void* pC;
    void* p10;
    void* p14;
};

struct Outer {
    void* p0;
    void* p4;
    Inner inner;
    void ctor(void* a, void* b, void* c, void* d, void* e, void* f);
};

extern "C" void __stdcall sub_6abba0(void*);
extern "C" void __stdcall sub_6abde0(void*);
extern "C" void __stdcall sub_60f0a0(void*);

void Outer::ctor(void* a, void* b, void* c, void* d, void* e, void* f)
{
    this->p0 = 0;
    this->p4 = 0;
    Inner tmp;
    tmp.p0 = a;
    tmp.p4 = b;
    tmp.p8 = c;
    if (c == 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)c + 4), 1);
    }
    tmp.pC = d;
    tmp.p10 = e;
    if (e != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)e + 4), 1);
    }
    sub_6abba0(&this->inner);
    sub_6abde0(this);
    sub_60f0a0(&tmp);
}
