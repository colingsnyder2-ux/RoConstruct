// from server: 100% by colin
extern "C" int __cdecl sub_69ECB0();
extern "C" int __cdecl sub_69E740();

int __cdecl sub_69EDF0()
{
    int v0;
    int v1;
    unsigned short v2;

    v0 = sub_69ECB0();
    if (v0 == 0)
        return 0;

    v1 = sub_69E740();
    if (*(unsigned int *)(v1 + 0xD0) == 0x21FFFF1)
        return 1;

    v1 = sub_69E740();
    v2 = 5;
    return (v2 < *(unsigned short *)(v1 + 0xD6)) ? 1 : 0;
}
