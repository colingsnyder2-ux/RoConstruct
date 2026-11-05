// from server: 68% by atomic.potato
struct ToggleFullscreenVerb
{
    unsigned char f();
};

extern "C" ToggleFullscreenVerb* __cdecl sub_007f3b1e();

unsigned char ToggleFullscreenVerb::f()
{
    return *reinterpret_cast<unsigned char *>(
        *reinterpret_cast<unsigned char **>(
            *reinterpret_cast<unsigned char **>(
                sub_007f3b1e()) + 4) + 0x20) + 0xfc;
}
