// from server: 84% by atomic.potato
typedef unsigned int UINT;
typedef unsigned long WPARAM;
typedef long LPARAM;
typedef int BOOL;

extern "C" void* __cdecl sub_80A31C();
extern "C" BOOL __stdcall PostMessageA(void*, UINT, WPARAM, LPARAM);

struct StealthLockPlayModeVerb
{
    void f();
};

void StealthLockPlayModeVerb::f()
{
    void* a = sub_80A31C();
    a = *(void**)((char*)a + 4);
    a = *(void**)((char*)a + 0x20);
    void* h = *(void**)((char*)a + 0x20);
    PostMessageA(h, 0x111, 0x8124, 0);
}
