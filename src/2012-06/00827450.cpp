// from server: 100% by Intel
unsigned int __cdecl getSurfaceMask(unsigned int index)
{
    switch (index)
    {
        case 0: return 1;
        case 1: return 2;
        case 2: return 4;
        case 3: return 8;
        case 4: return 0x10;
        case 5: return 0x20;
        default: return 0;
    }
}
