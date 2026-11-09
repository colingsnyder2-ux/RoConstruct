// from server: 87% by atomic.potato
extern "C" void* __cdecl GetSomething();
extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, int);

struct LockPlayModeVerb
{
    int f(int);
};

int LockPlayModeVerb::f(int)
{
    void* p = GetSomething();
    p = *(void**)((char*)p + 4);
    p = *(void**)((char*)p + 0x20);
    void* h = *(void**)((char*)p + 0x20);
    return PostMessageA(h, 0x111, 0x80ff, 0);
}
