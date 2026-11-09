// from server: 78% by atomic.potato
struct ToggleFullscreenVerb
{
    unsigned char f();
};

extern "C" ToggleFullscreenVerb* __cdecl GetToggleFullscreenVerb();

unsigned char ToggleFullscreenVerb::f()
{
    return *((unsigned char*)((*((unsigned long**)((char*)GetToggleFullscreenVerb() + 4))) + 0x20) + 0xfc);
}
