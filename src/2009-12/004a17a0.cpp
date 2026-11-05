// from server: 75% by atomic.potato
typedef unsigned int uint32_t;

extern "C" void __cdecl Call_4a1560(void *, void *);

void Function_4a17a0(uint32_t count, void *items, void *value)
{
    if (count != 0)
    {
        do
        {
            if (items != 0)
                Call_4a1560(items, value);
            --count;
            items = (char *)items + 0x44;
        }
        while (count != 0);
    }
}
