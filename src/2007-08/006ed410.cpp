// from server: 100% by colin
extern "C" int __cdecl sub_6ebd20();

void __stdcall sub_6ed410(int a1, int a2)
{
    if (sub_6ebd20() == 1)
    {
        if (a2 == 4)
        {
            *(int*)a1 = 0x1d;
            *(int*)(a1 + 4) = 0x20;
            return;
        }
        if (a2 == 1)
        {
            *(int*)a1 = 0x20;
            *(int*)(a1 + 4) = 0x1d;
            return;
        }
        if (a2 == 8)
        {
            *(int*)a1 = 0x1d;
            *(int*)(a1 + 4) = 0x20;
            return;
        }
        if (a2 == 2)
        {
            *(int*)a1 = 0x20;
            *(int*)(a1 + 4) = 0x1d;
            return;
        }
        *(int*)a1 = 0x59;
        *(int*)(a1 + 4) = 0x59;
        return;
    }

    if (a2 == 4)
    {
        *(int*)a1 = 0x2b;
        *(int*)(a1 + 4) = 0x1e;
        return;
    }
    if (a2 == 1)
    {
        *(int*)a1 = 0x1e;
        *(int*)(a1 + 4) = 0x2b;
        return;
    }
    if (a2 == 8)
    {
        *(int*)a1 = 0x2b;
        *(int*)(a1 + 4) = 0x1e;
        return;
    }
    if (a2 == 2)
    {
        *(int*)a1 = 0x1e;
        *(int*)(a1 + 4) = 0x2b;
        return;
    }
    *(int*)a1 = 0x5d;
    *(int*)(a1 + 4) = 0x5d;
}
