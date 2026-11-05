// from server: 78% by atomic.potato
extern "C" int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
extern "C" void * __cdecl GetApplication();

struct ToggleIDEModeVerb {
    struct VTable {
        int (__thiscall *IsEnabled)(ToggleIDEModeVerb *);
    };

    VTable *vtable;
    int Execute();
};

int ToggleIDEModeVerb::Execute()
{
    if (!vtable->IsEnabled(this))
        return 0;

    void *p = GetApplication();
    p = *(void **)((char *)p + 4);
    p = *(void **)((char *)p + 0x20);
    void *window = *(void **)((char *)p + 0x20);
    PostMessageA(window, 0x111, 0x80f5, 0);
    return 0;
}
