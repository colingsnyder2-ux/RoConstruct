// from server: 59% by atomic.potato
extern "C" void __cdecl UniversalTool(void *, void *);

int Function(void *arg)
{
    unsigned int value;
    if (*(unsigned int *)0x00b84a24 >= 0x10)
        value = *(unsigned int *)0x00b84a10;
    else
        value = 0x00b84a10;

    UniversalTool((void *)value, arg);
    return 1;
}
