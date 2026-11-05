// from server: 92% by atomic.potato
extern "C" void __cdecl Call983270(void *, unsigned int, unsigned int, void *);
extern "C" void __cdecl Call982114(void *);
extern "C" void Function5b5770();

void Function5b65e0(void *value)
{
    if (value != 0)
    {
        Call983270((char *)value + 8, 0x28, 0x28, Function5b5770);
        Call982114(value);
    }
}
