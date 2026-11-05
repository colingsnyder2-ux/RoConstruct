// from server: 92% by atomic.potato
extern "C" void __cdecl Call_7A8ADE(void *, int, int, void *);
extern "C" void __cdecl Call_7A799A(void *);

void Function_00510850(void *value)
{
    if (value != 0)
    {
        Call_7A8ADE((char *)value + 8, 0x18, 0x28, (void *)0x507810);
        Call_7A799A(value);
    }
}
