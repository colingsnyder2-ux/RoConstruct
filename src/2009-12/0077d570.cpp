// from server: 92% by atomic.potato
extern "C" void* __cdecl sub_44F600();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" long __stdcall InterlockedDecrement(long*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct S
{
};

int __cdecl f(void** p)
{
    void* v = sub_44F600();
    EnterCriticalSection(v);
    *p = *(void**)((char*)v + 0x18);
    *(void**)((char*)v + 0x18) = p;
    LeaveCriticalSection(v);
    InterlockedDecrement((long*)0x00B7B440);
    return 0;
}
