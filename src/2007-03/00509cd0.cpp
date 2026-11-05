// from server: 100% by tester
extern "C" {
void __cdecl sub_5145B0(int a, int b, int c);
void __cdecl sub_513EC0(int a, int b, double d);
void __cdecl sub_513F40(int a, int b, int c);
void __cdecl sub_513CD0(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);
void __cdecl sub_513990(int a, int b, double d0, double d1, double d2, double d3, double d4, double d5, double d6, double d7);
}

extern double g_7A1468;
extern double g_7A1460;
extern double g_7A1458;
extern double g_7A1450;
extern double g_79F400;
extern double g_7A1448;
extern double g_7A1440;
extern double g_7A1438;
extern double g_7A1430;

void __cdecl sub_5145D0(int a, int b, int c)
{
    if (a == 0)
        return;
    if (b == 0)
        return;

    sub_5145B0(a, b, c);

    sub_513EC0(a, b, g_7A1468);

    sub_513F40(a, b, 0xB18F);

    sub_513CD0(a, b, 0x7A26, 0x8084, 0xFA00, 0x80E8, 0x7530, 0xEA60, 0x3A98, 0x1770);

    sub_513990(a, b,
        g_7A1430,
        g_7A1438,
        g_7A1440,
        g_7A1448,
        g_79F400,
        g_7A1450,
        g_7A1458,
        g_7A1460);
}
