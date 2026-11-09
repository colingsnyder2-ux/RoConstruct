// from server: 79% by atomic.potato
extern "C" void* __cdecl GetGlobal();

struct ToggleIDEModeVerb
{
    bool f();
};

bool ToggleIDEModeVerb::f()
{
    void* p = GetGlobal();
    p = *(void**)((char*)p + 4);
    p = *(void**)((char*)p + 0x20);
    return *(unsigned char*)((char*)p + 0x10C) == 0;
}
