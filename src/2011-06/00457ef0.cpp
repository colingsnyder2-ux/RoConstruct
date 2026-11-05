// from server: 100% by atomic.potato
extern void G1_func_00457ba0(int, int, int);

struct RenderStatsItem
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        G1_func_00457ba0(a, b, c);
        return;
    }

    *(int*)b = 0x00c12d88;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
