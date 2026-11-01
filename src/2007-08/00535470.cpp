// from server: 100% by colin
extern "C" int __cdecl sub_5BF350(int, int, int);
extern "C" int __cdecl sub_5BF240(int, int, int);
extern "C" int __cdecl sub_56C740(int, int, int);

extern int dword_8ABE8C;

int __cdecl sub_535470(int a1)
{
    int v2 = sub_5BF350(a1, 2, 0);
    int v3 = sub_5BF240(a1, 1, dword_8ABE8C);
    sub_56C740(v3, v2, a1);
    return 0;
}
