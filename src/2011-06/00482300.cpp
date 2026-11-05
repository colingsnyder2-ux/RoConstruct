// from server: 88% by atomic.potato
struct ToggleFullscreenVerb
{
    unsigned char IsFullscreen();
};

extern "C" void* __cdecl GetFullscreenState();

unsigned char ToggleFullscreenVerb::IsFullscreen()
{
    void* a = GetFullscreenState();
    void* b = *(void**)((char*)a + 4);
    void* c = *(void**)((char*)b + 0x20);
    return *(unsigned char*)((char*)c + 0x100);
}
