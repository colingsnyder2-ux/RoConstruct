// from server: 100% by colin
extern "C" int __cdecl sub_0063db30(int);
extern "C" int __cdecl sub_0063cf10(int);

extern int* g_8c86d8;

void __cdecl sub_0063dcb0(int a1)
{
    int v = sub_0063db30(a1);
    sub_0063cf10(v);
    g_8c86d8[0x124 / 4] = a1;
}
