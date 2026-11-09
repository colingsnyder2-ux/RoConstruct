// from server: 100% by colin
extern "C" int (__cdecl *srand)(unsigned int);
extern "C" int __cdecl sub_005bf490(int a, int b);

int __cdecl sub_005c9aa0(int a)
{
    srand(sub_005bf490(a, 1));
    return 0;
}
