// from server: 72% by atomic.potato
struct ToggleIDEModeVerb
{
    unsigned char IsEnabled();
};

extern "C" void* __cdecl GetGlobal();

unsigned char ToggleIDEModeVerb::IsEnabled()
{
    void* a = GetGlobal();
    a = *(void**)((char*)a + 4);
    a = *(void**)((char*)a + 0x20);
    return *(unsigned char*)((char*)a + 0x108) == 0;
}
