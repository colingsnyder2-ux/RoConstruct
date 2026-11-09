// from server: 61% by Intel




extern "C" int __stdcall sub_631620(int, int);
extern "C" int __stdcall sub_6317a0(int);
extern "C" int __stdcall sub_6317d0(int, int);

int __stdcall sub_631812(int a1)
{
    int v1;
    int v2;
    int v3;

    v1 = sub_631620(0x869b78, 8);
    v2 = 0x400000;
    if (sub_6317a0(v2) != 0)
    {
        v3 = sub_6317d0(v2, a1 - v2);
        if (v3 != 0)
        {
            v3 = ((*(unsigned int *)(v3 + 0x24) >> 0x1f) ^ 1) & 1;
        }
    }
    return v3;
}
