// from server: 84% by atomic.potato
typedef unsigned long DWORD;
typedef long LONG;

extern "C" void* __cdecl CreateObject();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" LONG __stdcall InterlockedDecrement(LONG*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void* g_98b204;
extern "C" void* g_98b200;
extern "C" void* g_98b208;
extern "C" void* g_b7a124;

struct S
{
    void f(void**);
};

void S::f(void** p)
{
    void* s = CreateObject();
    EnterCriticalSection(s);
    *p = *(void**)((char*)s + 0x18);
    *(void**)((char*)s + 0x18) = *p;
    LeaveCriticalSection(s);
    EnterCriticalSection(g_b7a124);
}
