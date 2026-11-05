// from server: 84% by atomic.potato
extern "C" void* __cdecl GetGlobal();

extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, long);

struct LockPlayModeVerb
{
    void f();
};

void LockPlayModeVerb::f()
{
    void* a = GetGlobal();
    a = *(void**)((char*)a + 4);
    a = *(void**)((char*)a + 0x20);
    void* h = *(void**)((char*)a + 0x20);
    PostMessageA(h, 0x111, 0x80ff, 0);
}
