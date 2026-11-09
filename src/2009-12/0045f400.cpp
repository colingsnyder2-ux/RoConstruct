// from server: 84% by atomic.potato
extern "C" int __cdecl GetGlobalObject();
extern "C" int __stdcall PostMessageA(int, unsigned int, unsigned int, int);

struct ToggleFullscreenVerb
{
    void f();
};

void ToggleFullscreenVerb::f()
{
    int a = GetGlobalObject();
    int b = *(int *)(a + 4);
    int c = *(int *)(b + 0x20);
    int d = *(int *)(c + 0x20);
    PostMessageA(d, 0x111, 0x80f4, 0);
}
