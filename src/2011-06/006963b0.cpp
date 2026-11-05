// from server: 48% by atomic.potato
struct Configuration
{
};

typedef int (__thiscall *ConfigurationCallback)(void *, int, int, int);

int __cdecl f(void *value, int first, int second, int third)
{
    if (*(int *)((char *)value + 0x10) != 0)
    {
        ConfigurationCallback callback =
            *(ConfigurationCallback *)*(int *)((char *)value + 8);
        return callback((char *)value + 8, first, second, third);
    }
    return 0;
}
