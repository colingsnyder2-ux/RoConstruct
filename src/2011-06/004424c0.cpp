// from server: 70% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

typedef unsigned long DWORD;
typedef void* HANDLE;

extern "C" HANDLE __stdcall GetProcessHeap();
extern "C" int __stdcall HeapFree(HANDLE, DWORD, void*);

struct CProgressDialog
{
    void f();
};

void CProgressDialog::f()
{
    struct Block
    {
        void* vptr;
        volatile long refs;
    };

    Block* p = *(Block**)this;
    if (p != 0)
    {
        if (_InterlockedExchangeAdd(&p->refs, -1) == 1)
        {
            void (__thiscall* destroy)(Block*, int) =
                (void (__thiscall*)(Block*, int))(*(void**)p);
            destroy(p, 0);
            HeapFree(GetProcessHeap(), 0, p);
        }
    }
}
