// from server: 100% by Intel

int __cdecl sub_005d8be0(int arg)
{
    int v = arg + 1;
    if ((unsigned)v > 3u)
        return -1;
    switch (v)
    {
        case 0: return 9;
        case 1: return 6;
        case 2: return 3;
        case 3: return -1;
    }
    return -1;
}
