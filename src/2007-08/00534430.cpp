// from server: 100% by colin
extern "C" int __cdecl sub_005BF350(int, int, int);
extern "C" int __cdecl sub_005BF240(int, int, int);
extern "C" int __cdecl sub_005C0AC0(int, int, int);

extern int dword_008ABC2C;

int sub_00534430(int a1)
{
    int v2 = sub_005BF350(a1, 2, 0);
    int v3 = sub_005BF240(a1, 1, dword_008ABC2C);
    sub_005C0AC0(v3, v2, a1);
    return 0;
}
