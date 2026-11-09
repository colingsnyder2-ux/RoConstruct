// from server: 100% by intel
extern "C" int __cdecl sub_00833920(int a, int b, int c);
extern "C" int __cdecl sub_00833810(int a, int b, int c);
extern "C" int __cdecl sub_0083a6e0(int a, int b, int c);

extern int g_00de13b4;

int __cdecl sub_006a3b00(int a)
{
    int first = sub_00833920(a, 2, 0);
    int second = sub_00833810(a, 1, g_00de13b4);
    sub_0083a6e0(second, first, a);
    return 0;
}
