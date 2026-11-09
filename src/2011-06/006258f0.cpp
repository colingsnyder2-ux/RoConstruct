// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);

struct Inner_0061f980 {
    void init(void*, void*);
};

struct Base_00624d00 {
    void set(void*);
};

struct Obj_006258f0 {
    void func(void*, void*);
};

void Obj_006258f0::func(void* a, void* b)
{
    unsigned short* p = (unsigned short*)malloc(0x3c);
    if (p) {
        p[0] = 0;
        p[1] = 1;
    }
    char* esi = (char*)p + 4;
    if (esi) {
        ((Inner_0061f980*)esi)->init(a, b);
        *(void**)esi = (void*)0xa94b24;
        *(void**)(esi + 8) = (void*)0xa94b1c;
    } else {
        esi = 0;
    }
    ((Base_00624d00*)this)->set(esi);
    *(void**)a = esi;
    if (esi) {
        char* eax = esi + 5;
        if (eax) {
            eax -= 5;
        } else {
            eax = 0;
        }
        char* ecx = eax - 2;
        _InterlockedExchangeAdd((volatile long*)ecx, 1);
    }
}
