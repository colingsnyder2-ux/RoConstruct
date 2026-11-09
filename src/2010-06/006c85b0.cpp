// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl func_007a79a0(unsigned int);
extern "C" void* __cdecl func_0041b220(void*);
extern "C" void* __cdecl func_0041afe0(void*);
extern "C" void __cdecl func_004545b0(void*, void*, void*);
extern "C" void __cdecl func_006c73a0(void*, void*);
extern "C" void __cdecl func_006c8030(void*, void*, void*, int);
extern "C" void __cdecl func_0041fbe0(void*);
extern "C" void __cdecl func_0064d9a0(void*, void*);

extern "C" void* __stdcall func_009ea380(void*);

struct RefCounted {
    void* vptr;
    volatile long refcount;
};

struct Holder {
    void* ptr;
    void* ctrl;
};

struct S {
    void method(void* a, void* b, void* out);
};

void S::method(void* a, void* b, void* out)
{
    void* obj = func_007a79a0(0x48);
    void* esi = 0;
    if (obj != 0) {
        esi = 0;
        func_006c8030(obj, a, b, 0x7fffffff);
        esi = obj;
    }

    char buf[0x14];
    func_006c73a0(buf, esi);
    func_004545b0(buf, esi, esi);

    func_0041fbe0(this);
    func_0064d9a0(this, buf);

    void* (__stdcall *fn)(void*) = func_009ea380;
    fn((void*)0xc188b4);

    void* p1 = *(void**)(buf + 0);
    void* p2 = *(void**)(buf + 4);
    Holder h;
    h.ptr = p1;
    h.ctrl = p2;
    if (p2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), 1);
    }

    void* r = func_0041b220(buf);
    fn((void*)0xc007a8);

    void** src = (void**)r;
    void** dst = (void**)out;
    dst[0] = src[0];
    dst[1] = src[1];
    if (dst[1] != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)dst[1] + 8), 1);
    }

    func_0041afe0(buf);

    if (esi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void** vt = *(void***)esi;
            void (*dtor)(void*) = (void (*)(void*))vt[1];
            dtor(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt2 = *(void***)esi;
                void (*dtor2)(void*) = (void (*)(void*))vt2[2];
                dtor2(esi);
            }
        }
    }
}
