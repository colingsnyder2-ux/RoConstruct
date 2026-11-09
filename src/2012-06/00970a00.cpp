// from server: 75% by Intel
extern "C" int __stdcall func_00970a00(int arg)
{
    int v = arg - 70;
    if (v > 13)
        return 0;

    static const unsigned char jumpTable[14] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
    };

    switch (jumpTable[v])
    {
    case 0: return 0x20;
    case 1: return 0x18;
    case 2: return 0x10;
    case 3: return 0x0F;
    default: return 0;
    }
}
