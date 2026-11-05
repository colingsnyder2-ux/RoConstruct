// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);
extern "C" void* __stdcall InterlockedExchange(void* volatile*, void*);

struct Inner {
    void** vptr;
    long ref1;
    long ref2;
};

struct CInstanceExplorer {
    char pad0[0x20];
    void* hwnd;
    char pad24[0x384 - 0x24];
    char field384[0x24];
    char field3a8[4];
    void method_41bc00(void*);
};

void CInstanceExplorer::method_41bc00(void* p)
{
    Inner* inner = (Inner*)p;
    if (inner)
    {
        _InterlockedExchangeAdd(&inner->ref1, 1);
    }
    void* local = p;
    char flag = 0;
    method_41bc00(&local);
    if (!InterlockedExchange((void* volatile*)&field3a8, (void*)1))
    {
        PostMessageA(hwnd, 0x46c, 0, 0);
    }
    if (inner)
    {
        if (_InterlockedExchangeAdd(&inner->ref1, -1) == 1)
        {
            ((void (__thiscall*)(Inner*))inner->vptr[1])(inner);
            if (_InterlockedExchangeAdd(&inner->ref2, -1) == 1)
            {
                ((void (__thiscall*)(Inner*))inner->vptr[2])(inner);
            }
        }
    }
}
