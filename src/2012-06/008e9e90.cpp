// from server: 64% by atomic.potato
extern "C" void __cdecl function_008e9ac0(int, void *, int);

struct FloorWire
{
};

void __cdecl f(void *a, int b, int c)
{
    if (c != 4)
    {
        function_008e9ac0(0, a, c);
        return;
    }

    *(unsigned int *)b = 0x00dfa4e0;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
