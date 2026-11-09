// from server: 87% by atomic.potato
extern "C" int __cdecl GetGlobalObject();
extern "C" int __stdcall PostMessageA(int, unsigned int, unsigned int, int);

struct ToggleFullscreenVerb
{
    int f(int);
};

int ToggleFullscreenVerb::f(int)
{
    int a = GetGlobalObject();
    a = *(int *)(a + 4);
    a = *(int *)(a + 0x20);
    int h = *(int *)(a + 0x20);
    PostMessageA(h, 0x111, 0x80f4, 0);
    return 0;
}
