// from server: 80% by atomic.potato
typedef long LONG;
typedef void* LPVOID;

extern "C" void* __cdecl AllocateObject();
extern "C" LONG __stdcall InterlockedDecrement(volatile LONG*);
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

extern "C" void* g_98b200;
extern "C" void* g_98b204;
extern "C" void* g_98b208;
extern "C" void* g_B7B438;

struct S
{
    void f(void*);
};

void S::f(void* p)
{
    unsigned char* object;
    LONG value;

    object = (unsigned char*)AllocateObject();
    EnterCriticalSection(g_98b204);
    value = *(LONG*)(object + 0x18);
    *(LONG*)p = value;
    *(LONG*)(object + 0x18) = (LONG)p;
    InterlockedDecrement((volatile LONG*)g_98b200);
    LeaveCriticalSection(g_98b208);
}
