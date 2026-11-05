// from server: 100% by atomic.potato
extern "C" unsigned char g_00e31abf;

int f(const unsigned char value)
{
    if (g_00e31abf && ((value & 0x38) == 0x28) && value != (value & 0x38))
        return 1;
    return 0;
}
