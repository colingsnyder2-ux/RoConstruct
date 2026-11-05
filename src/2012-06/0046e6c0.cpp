// from server: 100% by atomic.potato
typedef unsigned long DWORD;
typedef int BOOL;

extern "C" DWORD __declspec(dllimport) __stdcall GetProcessHeap();
extern "C" BOOL __declspec(dllimport) __stdcall HeapFree(DWORD, DWORD, void*);

struct S
{
    void __stdcall f();
};

void __stdcall S::f()
{
    void* p = *(void**)this;
    void (__thiscall *d)(void*, int) = *(void (__thiscall **)(void*, int))p;
    d(this, 0);
    HeapFree(GetProcessHeap(), 0, this);
}
